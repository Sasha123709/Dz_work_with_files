#include <iostream>
#include <windows.h>
#include "main.h"
#include "badwords.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include "color.h"
using namespace std;

int badwords() {
	ifstream file("file.txt");
	ifstream badfile("badwordslist.txt");
	ofstream outfile("outfile.txt");

	if (!file || !badfile || !outfile) {
		setColor(12);
		cout << "ERROR!";
		setColor(7);
		return 0;
	}
	vector<string> bad_words;
	string word;
	while(badfile >> word) {
		bad_words.push_back(word);
	}
	while (file >> word) {
		if (find(bad_words.begin(), bad_words.end(), word) == bad_words.end()) {
			outfile << word << ' ';
		}
	}
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
	file.close();
	badfile.close();
	outfile.close();
	return 0;
}