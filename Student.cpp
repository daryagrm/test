#include "Student.h"

using std::cout;
using std::cin;
using std::endl;

Student::Student() {
	cout << "\t" << "STUDENT()" << endl;
	init();
}
Student::Student(
	const char* nm,
	int n,
	int *g
) {
	cout << "\t" << "STUDENT(...)" << endl;
	init();
	set_name(nm);
	set_groupNum(n);
	set_grades(g);
}
Student::Student(const Student &st) {
	cout << "\t" << "STUDENT(const STUDENT &st)" << endl;
	init();
	set_name(st.name);
	set_groupNum(st.group_num);
	set_grades(st.grades);
}
Student::~Student() {
	cout << "\t" << "~STUDENT()" << endl;
	delete[] name;
}

void Student::init() {
	name = nullptr;
	group_num = 0;
	for (int i = 0; i < 5; ++i)
		grades[i] = 0;
}

void Student::set_name(const char* nm) {
	int size = _strlen(nm);
	delete[] name;
	name = nullptr;
	if (size++) {
		name = new char[size];
		_strcpy(name, nm, size);
	}
}
void Student::set_groupNum(int n) {
	group_num = n;
}
void Student::set_grades(const int* g) {
	for (int i = 0; i < 5; ++i)
		grades[i] = g[i];
}

const char* Student::get_name() {
	return name;
}
int Student::get_groupNum() const {
	return group_num;
}
const int* Student::get_grades() {
	return grades;
}

Student& Student::operator=(const Student &st) {
	if (this != &st) {
		set_name(st.name);
		set_groupNum(st.group_num);
		set_grades(st.grades);
	}
	return *this;
}

std::istream& operator>>(std::istream& is, Student &st) {
	char *nm;
	int num;
	int gr[5];
	nm = read("Enter student's name: ");
	cout << "Enter gurp number: ";
	cin >> num;
	if (num < 1)
		throw exceptions("group number < 1");
	cin.get();
	for (int i = 0; i < 5; ++i) {
		cout << "Enter mark " << i + 1 << ": ";
		cin >> gr[i];
		if (gr[i] < 2 || gr[i] > 5) {
			delete[] nm;
			cin.get();
			throw exceptions("grade > 5 or grade < 2");
		}
	}
	cin.get();
	st.set_name(nm);
	st.set_groupNum(num);
	st.set_grades(gr);
	delete[] nm;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Student &st) {
	os << "Name: " << st.name << ", group: " << st.group_num << endl;
	return os;
}