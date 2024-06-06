#include <iostream>
#include <string>
#include <windows.h>
#include <iostream>
#pragma execution_character_set("utf-8")
using namespace std;

typedef bool(*CheckCharactersFunction)(const char*, const char*);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::locale::global(std::locale(""));

    cout << "Введите строчку для поиска символов: ";
    string line;
    getline(cin, line);

    cout << "Введите символы для поиска в строке: ";
    string sim;
    getline(cin, sim);                              

    HINSTANCE hDLL = LoadLibrary(L"LibDLL.dll");
    typedef bool (*serchstr)(const char*, const char*);

    serchstr findCharsInString = (serchstr)GetProcAddress(hDLL, "serchstr");

    bool result = findCharsInString(line.c_str(), sim.c_str());

    if (result) {
        cout << "Все нашло" << endl;
    }
    else {
        cout << "Не все нашло" << endl;
    }

    FreeLibrary(hDLL);

    return 0;
}



