#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <string>


BOOL WINAPI Clip(std::string utf8_str)
{
    // UTF-16文字列の準備
    // hMemにコピーする文字列が入る
    size_t length = MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, nullptr, 0); // ヌル文字入りの文字数
    size_t buffer_size = length * sizeof(char16_t); // バイト数
    HGLOBAL hMem = GlobalAlloc(GMEM_FIXED, buffer_size);
    if (hMem == NULL) {
        return FALSE;
    }
    LPWSTR pStr = (LPWSTR)GlobalLock(hMem);
    MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, pStr, buffer_size);
    GlobalUnlock(hMem);

    // クリップボードにコピー
    if (!OpenClipboard(NULL)) {
        return FALSE;
    }
    EmptyClipboard();
    SetClipboardData(CF_UNICODETEXT, hMem);
    CloseClipboard();

    return TRUE;
}

int main()
{
    // 入力
    std::string s;
    for (std::string line; std::getline(std::cin, line); ) {
        s += line + "\r\n";
    }
    s.pop_back(); // 最後の改行を除去する

    // 変換
    bool ok = Clip(s);
    if (ok) {
        return 0;
    }
    else {
        return -1;
    }
}