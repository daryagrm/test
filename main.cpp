#include <iostream>
#include "Student.h"

int main() {
	const int max_student = 10;
	Student s[max_student];

	for (int i = 0; i < max_student; i++) {
		s[i].PrintStudent();
	}

	std::cin.get();
	std::cin.get();
	return 0;
}