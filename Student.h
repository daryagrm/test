#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <iostream>
#include "string.h"
#include "exceptions.h"

class Student {
public:
	Student();
	Student(
		const char* nm,
		int n,
		int *g
	);
	Student(const Student &st);
	~Student();
	void set_name(const char* nm);
	void set_groupNum(int n);
	void set_grades(const int *g);

	const char* get_name();
	int get_groupNum() const;
	const int* get_grades();

	Student& operator=(const Student &st);
	friend std::ostream& operator<<(std::ostream& os, const Student &st);
	friend std::istream& operator>>(std::istream& is, Student &st);
private:
	char *name;
	int group_num;
	int grades[5];
	void init();
};

#endif