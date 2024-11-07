#include <iostream>
#include "students.h"
#include "main.h"
#include <vector>
#include <fstream>
#include <windows.h>
#include "color.h"
using namespace std;


float avg(vector<int>& scores) {
    float sum = 0;
    for (int score : scores) {
        sum += score;
    }
    return sum / scores.size();
}
int score()
{
    ifstream file("scores.txt");
    if (!file) {
        setColor(12);
        cout << "ERROR!";
        setColor(7);
        return 0;
    }

    string name, surname;
    int score = 0;
    vector<int> scores;
    int minbal;
    cout << "Enter the minimal score: ";
    cin >> minbal;
    cout << "Students which have score min that ";
    setColor(12);
    cout << minbal << endl;
    setColor(7);
    while (file >> surname >> name >> score) {
        scores.push_back(score);
        if (score < minbal) {
            cout << surname << ' ' << name << ' ';
            setColor(12);
            cout << score << endl;
            setColor(7);
        }
    }

    float avgscore = avg(scores);
    cout << "Avg score of group ";
    setColor(2);
    cout << avgscore <<endl;
    setColor(7);
    cout << "Do you want back to menu?(y/n): ";
    char yn;
    cin >> yn;
    if (yn == 'y') {
        main();
    }
    return 0;
}


