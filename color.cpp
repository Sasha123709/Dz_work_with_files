#include <windows.h>
#include "main.h"
#include "students.h"
#include "badwords.h"


void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}