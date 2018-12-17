#include <iostream>
#include "Student.h"
#include "Group.h"
#include "exceptions.h"
#include <conio.h>
using namespace std;

int main() {
		int ch;
		char w;
		Student st;
		Group gr;
		while (w=_getch()) {
			cout <<"\n(1) Add new student"
				 <<"\n(2) Remove student"
				 <<"\n(3) Show" << endl;
			cout << "Enter: ";
			cin >> ch;
			cin.get();
			switch (ch) {
			case 1: {
				try {
					cin >> gr;
				}
				catch (exceptions e) {
					cout << "Error: " << e.what() << endl;
				}
				break;
			}
			case 2: {
				gr.show();
				if (!gr.empty()) {
					cout << "Enter: ";
					cin >> ch;
					cin.get();
					try {
						gr - --ch;
						cout << "\tSuccess" << endl;
					}
					catch (exceptions e) {
						cout << "Error: " << e.what() << endl;
					}
				}
				break;
			}
			case 3: {
				cout << gr;
				break;
			}
			default: {
				cout << "You've entered wrong number." << endl; 
				break;
			}
			}
		}
	return 0;
}