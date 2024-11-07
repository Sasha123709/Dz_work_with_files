#include <iostream>
#include "main.h"
#include "trans.h"
#include <fstream>
#include "color.h"
#include <vector>
#include <cctype>
#include <Windows.h>
using namespace std;

int trans() {
    
    vector<pair<char, string>> leters = {
        {'�', "a"}, {'�', "b"}, {'�', "v"}, {'�', "h"}, {'�', "d"},
        {'�', "e"}, {'�', "ie"}, {'�', "zh"}, {'�', "z"}, {'�', "y"},
        {'�', "i"}, {'�', "i"}, {'�', "j"}, {'�', "k"}, {'�', "l"},
        {'�', "m"}, {'�', "n"}, {'�', "o"}, {'�', "p"}, {'�', "r"},
        {'�', "s"}, {'�', "t"}, {'�', "u"}, {'�', "f"}, {'�', "kh"},
        {'�', "ts"}, {'�', "ch"}, {'�', "sh"}, {'�', "shch"}, {'�', "iu"},
        {'�', "ia"}
    };

    
    ifstream ukr("ukr.txt");
    ofstream eng("eng.txt", ios::app);  

    if (!ukr || !eng) {
        setColor(12);
        cout << "ERROR!";
        setColor(7);
        return 0;
    }

    char c;
    while (ukr.get(c)) {
        c = tolower(c);  
        for (const auto& letter : leters) {
            if (letter.first == c) {
                eng << letter.second;
                break;
            }
        }
    }

    ukr.close();
    eng.close();
    Sleep(1000);
    cout << "Please wait";
    for (int i = 0; i < 3; i++) {
        cout << '.';
        Sleep(1000);
    }
    Sleep(1000);
    setColor(2);
    cout << "\nReady!" << endl;
    setColor(7);
    cout << "Do you want back to menu?(y/n): ";
    char yn;
    cin >> yn;
    if (yn == 'y') {
        main();
    }
    return 0;
}
