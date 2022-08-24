// TUILib.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "TUILib.h"

int32_t interval = 2000;
tuilib::Screen<std::string> scrn;
uint16_t hight = 6;
uint16_t width = 12;
const std::string BLOCK = "|";

volatile sig_atomic_t e_flag = 0;

void abortHandler(int signum);
void onTimer(void);

void abortHandler(int signum) {
    //std::cout << "\033[?1049l" << std::flush;
    std::cout << "abortHandler" << std::flush;
    exit(0);
}

void onTimer() {
    static int counter = 0;
    counter %= 10;
    scrn.clearBuffer(std::to_string(counter));
    for (auto i = 0; i < hight; ++i) {
        for (auto j = 0; j < width; ++j) {
            scrn.setCharactor(i + 1, j + 1, std::to_string(counter));
        }
    }
    scrn.reflectScreen();
    ++counter;
}

//https://docs.microsoft.com/ja-jp/windows/win32/intl/code-page-identifiers?redirectedfrom=MSDN
// SHIFT_JISのコードポイント
constexpr int CP_SHIFT_JIS = 932;

int main() {
#ifdef _WIN32
    //setvbuf(stdout, nullptr, _IOFBF, 1024);
    SetConsoleOutputCP(CP_UTF8);
#endif
    
    if (signal(SIGINT, abortHandler) == SIG_ERR) {
        exit(1);
    }
    using namespace tuilib;

    std::system("cls");
    scrn.createFrameBuffer(hight, width);
    scrn.clearBuffer(BLOCK);
    scrn.cursor = false;
    scrn.reflectScreen();
    while (true) {
        onTimer();
        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
    }
    return 0;
}
