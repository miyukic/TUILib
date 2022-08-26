#pragma once
#include "Dll.hpp"

namespace tuilib {
    /// <summary>
    /// テキストの属性を表します。
    /// https://docs.microsoft.com/ja-jp/windows/console/console-virtual-terminal-sequences#screen-colors
    /// </summary>
    enum class MYKLIB_API TextAttribute {
                                        /* 説明               動作                               */
        DEFAULT                 = 0, 	// Default 	        すべての属性を変更前の既定の状態に戻します
        BOLD_BRIGHT             = 1, 	// ボールド/明 	    明度と彩度のフラグを前景色に適用します
        UNDERLINE               = 4, 	// Underline 	    下線を追加します
        NEGATIVE                = 7, 	// 負 	            前景色と背景色を入れ替えます
        NO_BOLD_BRIGHT          = 22, 	// ボールドなし/明 	明度と彩度のフラグを前景色から削除します
        NO_UNDERLINE            = 24, 	// 下線なし 	        下線を削除します
        POSITIVE                = 27, 	// 正 (非負) 	    前景色と背景値を標準に戻します
        FORE_BLACK	            = 30, 	// 前景黒 	        非ボールドの明るい黒を前景に適用します
        FORE_RED 	            = 31, 	// 前景赤 	        非ボールドの明るい赤を前景に適用します
        FORE_GREEN 	            = 32, 	// 前景緑 	        非ボールドの明るい緑を前景に適用します
        FORE_YELLOW 	        = 33, 	// 前景黄 	        非ボールドの明るい黄を前景に適用します
        FORE_BLUE 	            = 34, 	// 前景青 	        非ボールドの明るい青を前景に適用します
        FORE_MAGENTA 	        = 35, 	// 前景マゼンタ 	    非ボールドの明るいマゼンタを前景に適用します
        FORE_CYAN 	            = 36, 	// 前景シアン 	    非ボールドの明るいシアンを前景に適用します
        FORE_WHITE 	            = 37, 	// 前景白 	        非ボールドの明るい白を前景に適用します
        FORE_EXTENDED           = 38, 	// 前景拡張 	        前景に拡張色の値を適用します
        FORE_DEFAULT 	        = 39, 	// 前景既定値 	    既定値の前景部分のみを適用します
        BACK_BLACK 	            = 40, 	// 背景黒 	        非ボールドの明るい黒を背景に適用します
        BACK_RED                = 41, 	// 背景赤 	        非ボールドの明るい赤を背景に適用します
        BACK_GREEN 	            = 42, 	// 背景緑 	        非ボールドの明るい緑を背景に適用します
        BACK_YELLOW 	        = 43, 	// 背景黄 	        非ボールドの明るい黄を背景に適用します
        BACK_BLUE 	            = 44, 	// 背景青 	        非ボールドの明るい青を背景に適用します
        BACK_MAGENTA 	        = 45, 	// 背景マゼンタ 	    非ボールドの明るいマゼンタを背景に適用します
        BACK_CYAN 	            = 46, 	// 背景シアン 	    非ボールドの明るいシアンを背景に適用します
        BACK_WHITE 	            = 47, 	// 背景白 	        非ボールドの明るい白を背景に適用します
        BACK_EXTENDED           = 48, 	// 背景拡張 	        背景に拡張色の値を適用します
        BACK_DEFAULT            = 49, 	// 背景既定値 	    既定値の背景部分のみを適用します
        BRIGHT_FOREGROUND_BLACK     = 90, 	// 明るい前景黒 	        ボールドの明るい黒を前景に適用します
        BRIGHT_FOREGROUND_RED       = 91, 	// 明るい前景赤 	        ボールドの明るい赤を前景に適用します
        BRIGHT_FOREGROUND_GREEN     = 92, 	// 明るい前景緑 	        ボールドの明るい緑を前景に適用します
        BRIGHT_FOREGROUND_YELLOW    = 93, 	// 明るい前景黄 	        ボールドの明るい黄を前景に適用します
        BRIGHT_FOREGROUND_BLUE      = 94, 	// 明るい前景青 	        ボールドの明るい青を前景に適用します
        BRIGHT_FOREGROUND_MAGENTA   = 95, 	// 明るい前景マゼンタ 	ボールドの明るいマゼンタを前景に適用します
        BRIGHT_FOREGROUND_CYAN      = 96, 	// 明るい前景シアン 	    ボールドの明るいシアンを前景に適用します
        BRIGHT_FOREGROUND_WHITE     = 97, 	// 明るい前景白 	        ボールドの明るい白を前景に適用します
        BRIGHT_BACKGROUND_BLACK     = 100,	// 明るい背景黒 	        ボールドの明るい黒を背景に適用します
        BRIGHT_BACKGROUND_RED       = 101,	// 明るい背景赤 	        ボールドの明るい赤を背景に適用します
        BRIGHT_BACKGROUND_GREEN     = 102,	// 明るい背景緑 	        ボールドの明るい緑を背景に適用します
        BRIGHT_BACKGROUND_YELLOW    = 103,	// 明るい背景黄 	        ボールドの明るい黄を背景に適用します
        BRIGHT_BACKGROUND_BLUE      = 104,	// 明るい背景青 	        ボールドの明るい青を背景に適用します
        BRIGHT_BACKGROUND_MAGENTA   = 105,	// 明るい背景マゼンタ 	ボールドの明るいマゼンタを背景に適用します
        BRIGHT_BACKGROUND_CYAN      = 106,	// 明るい背景シアン 	    ボールドの明るいシアンを背景に適用します
        BRIGHT_BACKGROUND_WHITE     = 107	// 明るい背景白 	        ボールドの明るい白を背景に適用します
    };
}
