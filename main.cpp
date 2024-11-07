#include <iostream>
#include <windows.h>
#include "main.h"
#include "students.h"
#include "badwords.h"
#include "trans.h"
#include "color.h"
using namespace std;

int main() {
	cout << "\t\tMenu\n1)Find a score ang avg of group of students\n2)Filter bad words\n3)Translit from ukr to eng\n0)Exit\n";
	int choice = 1;
	while (choice!=0) {
		cout << "Your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			score();
			break;
		case 2:
			badwords();
			break;
		case 3:
			trans();
			break;
		default:
			break;
		}
		return 0;
	}
	
}