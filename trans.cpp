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
        {'à', "a"}, {'á', "b"}, {'â', "v"}, {'ã', "h"}, {'ä', "d"},
        {'å', "e"}, {'º', "ie"}, {'æ', "zh"}, {'ç', "z"}, {'è', "y"},
        {'³', "i"}, {'¿', "i"}, {'é', "j"}, {'ê', "k"}, {'ë', "l"},
        {'ì', "m"}, {'í', "n"}, {'î', "o"}, {'ï', "p"}, {'ð', "r"},
        {'ñ', "s"}, {'ò', "t"}, {'ó', "u"}, {'ô', "f"}, {'õ', "kh"},
        {'ö', "ts"}, {'÷', "ch"}, {'ø', "sh"}, {'ù', "shch"}, {'þ', "iu"},
        {'ÿ', "ia"}
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
