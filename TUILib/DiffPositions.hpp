#pragma once

#include "TextAttribute.hpp"
#include "Dll.hpp"

#include <vector>
#include <iostream>
#include <cstdint>
#include <optional>
#include <map>


namespace tuilib {

    template<typename T>
    struct MYKLIB_API DiffProperty {
        uint16_t row;               // 行
        uint16_t cul;               // 列
        T charactor;                // 文字
        std::vector<TextAttribute> textAttr; // テキストの付加属性
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
