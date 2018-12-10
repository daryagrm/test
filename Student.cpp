#include <iostream>
#include "Student.h"

int Student::quantity = 0;

Student::Student() {
	Init();
}

void Student::Init(void) {
	quantity++;
	std::cout << "Student form #" << quantity << std::endl;
	std::cout << ">> Name: ";
	std::cin >> name;
	std::cout << ">> surname: ";
	std::cin >> surname;
	std::cout << ">> group_number: ";
	std::cin >> group_number;
	std::cout << ">> Score\n";

	for (int i = 0; i < MAX; i++) {
		std::cout << i + 1 << ": ";
		std::cin >> score[i];
	}

	float gpa = GPA(score, MAX);
	std::cout << "GPA = " << gpa << "\n\n";
}

Student::Student(std::string n, std::string sn, int g, int sc[]) {
	name = n;
	surname = sn;
	group_number = g;
	score[MAX] = sc[MAX];
}

void Student::PrintStudent(void) {
	float gpa = GPA(score, MAX);
	std::cout << "\n----------------\n" << std::endl;
	if (gpa >= 4.0) {
		std::cout << "Name: " << name << "\nSurname: " << surname
			<< "\nGroup number: " << group_number << "\nScore: ";
		for (int i = 0; i < MAX; i++) {
			std::cout << score[i] << " ";
		}
		std::cout << "\nGPA: " << gpa << std::endl;
	}
}