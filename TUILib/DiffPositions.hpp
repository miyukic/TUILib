#pragma once

#include <vector>
#include <iostream>
#include <cstdint>
#include <optional>
#include <map>

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


    enum class MYKLIB_API TextAttribute;

    template<typename T>
    struct MYKLIB_API DiffProperty {
        uint16_t row;
        uint16_t cul;
        T charactor;
        std::vector<TextAttribute> textAttr;
    };

    template<typename T>
    class MYKLIB_API DiffPositions {
        std::map<uint16_t, DiffProperty<T>> _data;
    public:
        void clear() {
            _data.clear();
        }

        //デストラクタ
        ~DiffPositions() {
            //裏スクリーンバッファを元に戻す
            std::cout << "\033[?1049l" << std::flush;
        }

        //変更点をpush
        void pushBack(uint16_t row, uint16_t cul, T charactor, std::vector<TextAttribute> attributes) {
            auto dp = DiffProperty<T>{row, cul, charactor, attributes};
            //auto [itr, b] = _data.try_emplace(row, std::move(dp));
            _data.emplace(row, std::move(dp));
        }
        
        //指定行が変更されたか(row)
        bool isChanged(uint16_t row) {
            return _data.contains(row);
        }

    };
}
