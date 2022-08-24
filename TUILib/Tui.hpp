#pragma once
#include <cstddef>
//#include <errhandlingapi.h>
#include <iostream>
#include <cstdint>
#include <stdint.h>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <optional>
#include <algorithm>
#include <cstdlib>

#include "DiffPositions.hpp"

#ifdef _WIN32
#   include <Windows.h>
#   include <io.h>
#endif

#ifdef MYKLIBL_EXPORTS
#   ifdef _WINDLL
#       define MYKLIB_API __declspec(dllexport)
#   elif __linux__
#       define MYKLIB_API 
#   endif
#else
#   ifdef _WINDLL
#       define MYKLIB_API __declspec(dllimport)
#   elif __linux__
#       define MYKLIB_API
#   else //何も指定しない
#       define MYKLIB_API 
#       define MYKLIB_API 
#   endif
#endif

namespace tuilib {

    template<class T>
    class MYKLIB_API Screen {
        bool _doReflesh = true; //画面再描画フラグ
        uint16_t _hight = 1;
        uint16_t _width = 1;
        std::vector<T> _frameBuffer;
        std::vector<T> _preFrameBuffer;
        DiffPositions<T> _diffs;
    public:
        bool cursor = true;
    private:
        void refleshScreen() {
            std::cout << "\033[?1049h" << "\033[1d" << "\033[1G" << std::flush;
            auto h = _hight;
            auto w = _width;
            for (decltype(h) i = 0; i < h; ++i) {
                for (decltype(w) j = 0; j < w; ++j) {
                    std::cout << refFrameBuffer(i + 1, j + 1);
                }
                std::cout << std::endl;
            }
            this->_preFrameBuffer = _frameBuffer;
        }

        DiffPositions<T>& getDiffPositions() {
            return _diffs;
        }

        //位置(row,cul)を指定して任意文字(charactor)で書き換える。
        void putc(const DiffProperty<T>& dp) {
            std::cout
            << "\033[" << dp.row << "d"
            << "\033[" << dp.cul << "G"
            << dp.charactor;
        }

        //1行単位で書き換える。
        void put1LineDiff(uint16_t row, const T& diff) {
            std::cout
                << "\033[" << row << "d"
                << "\033[1G"
                << diff;
        }

        //差分を書き換える。
        void diffOverWrite() {
            auto h = _hight;
            for (uint16_t i = 0; i < h; ++i) {
                if (_diffs.isChanged(static_cast<uint16_t>(i + 1))) {
                    put1LineDiff(i + 1, refFrameBuffer(i + 1));
                }
            }
        }

        T& frameBufferAt(uint16_t row, uint16_t cul) {
            return _frameBuffer.at(_hight * (row - 1) + (cul - 1));
        }


    public:
        void printScreenBuffer() const {
            for (auto i : _frameBuffer) {
                std::cout << i << std::endl;
            }
        }

        //スクリーンバッファー作成、縦(hight),横(width)のサイズを指定する
        void createFrameBuffer(uint16_t hight, uint16_t width) {
            _hight = hight;
            _width = width;
            _frameBuffer.resize(hight * width);
            _doReflesh = true;
#ifdef _WIN32
            //TODO conhostの対応
            //if (_isatty(1)) {
            //    if (SetConsoleMode(
            //                GetStdHandle(STD_OUTPUT_HANDLE),
            //                ENABLE_VIRTUAL_TERMINAL_PROCESSING)) {
            //        //std::cerr << GetLastError() << std::endl;
            //    }
            //}
#endif
        }

        //任意の位置(row, cul)に任意の字(charactor)を配置, textattrに文字色等の設定を配列(vector)で渡す
        void setCharactor(
                uint16_t row, uint16_t cul,
                const T& charactor,
                const std::vector<TextAttribute>& txtattr = {} 
                ) noexcept(false) {
            //std::cout << _frameBuffer.size() << std::endl;
            _frameBuffer.at(((row - 1) * _width) + cul - 1) = charactor;
            _diffs.pushBack(row, cul, charactor, txtattr);
        }

        struct Propaty {

        };

        //任意の位置(row, cul)の文字を返す(読み取り専用)
        const T& refFrameBuffer(
                uint16_t row, uint16_t cul) const noexcept(false) {
            //std::cout << "debug row=" << row << " cul=" << cul  << " " << _frameBuffer[((row - 1) * _width) + cul - 1] << std::endl; 
            return _frameBuffer.at(((row - 1) * _width) + cul - 1);
        }

        //任意の行(row)の文字列を返す(読み取り専用)
        T refFrameBuffer(uint16_t row) const noexcept(false) {
            T ret;
            auto h = _hight;
            auto w = _width;
            for (size_t i = 0; i < w; ++i) {
                ret += _frameBuffer[((row - 1) * w) + i];
            }
            return ret;
        }

#ifdef TEST__
#include <algorithm>
#endif
        // 空白文字で埋める
        void clearBuffer(T blank = " ") {
            _frameBuffer = std::vector<T>(_hight * _width, blank);
            _doReflesh = true;
        }

        //フレームバッファの内容をコンソールに反映
        void reflectScreen() {
            if (cursor) {
                std::cout << "\033[?25h" << std::flush;
            } else {
                std::cout << "\033[?25l" << std::flush;
            }
            if (_doReflesh) {
                refleshScreen();
                _doReflesh = false;
            } else {
                diffOverWrite();
            }
            std::cout << std::flush;
            _diffs.clear();
        }
    };
}
