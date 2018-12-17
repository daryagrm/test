#include <iostream>
#include "Group.h"

using std::cout;
using std::cin;
using std::endl;

Group::Group() {
	cout << "\t" << "GROUP()" << endl;
	init(nullptr, 0, freq);
}
Group::Group(const Student *st, int l) {
	cout << "\t" << "GROUP(...)" << endl;
	init(st, l, l);
}
Group::Group(const Group &GP) {
	cout << "\t" << "GROUP(const GROUP &GP)" << endl;
	init(GP.sts, GP.st_len, GP.size);
}
Group::~Group() {
	cout << "\t" << "~GROUP()" << endl;
	delete[] sts;
}

void Group::init(
	const Student *st,
	int l,
	int s
) {
	size = s;
	st_len = l;
	sts = new Student[s];
	for (int i = 0; i < l; ++i)
		sts[i] = st[i];
}

void Group::operator+=(const Student &st) {
	int i;
	int tmp = 0;
	int num = st.get_groupNum();

	if (!st_len) {
		sts[st_len++] = st;
		return;
	}

	for (i = 0; i < st_len; ++i) {
		if (sts[i].get_groupNum() < num)
			tmp = i;
		if (sts[i].get_groupNum() == num)
			break;
	}
	if (i < st_len) {
		while (sts[i].get_groupNum() == num) i++;
		for (int j = st_len - 1; j >= i; --j)
			sts[j + 1] = sts[j];
		sts[i] = st;
	}
	else {
		int j = st_len - 1;
		do {
			sts[j + 1] = sts[j];
		} while (--j > tmp);
		sts[tmp + 1] = st;
	}
	if (++st_len == size) {
		sts = realloc(sts, size, size + freq);
		size += freq;
	}
}
void Group::operator-(int n) {
	if (n < 0 || n >= st_len)
		throw exceptions("number < \"0\" or number > \"number of students\"");
	for (int j = n + 1; j < st_len; ++j)
		sts[j - 1] = sts[j];
	--st_len;
}

void Group::show() {
	cout << "Students:\n";
	for (int i = 0; i < st_len; ++i) {
		cout << "\t|" << i + 1 << "|" << sts[i];
	}
	if (!st_len) cout << "\t\tempty!" << endl;
}
bool Group::empty() {
	return ((st_len) ? false : true);
}
std::ostream& operator<<(std::ostream& os, const Group &GP) {
	int i, j;
	int s;
	const int *gr;
	bool flag = false;
	os << "Students:\n";
	for (i = 0; i < GP.st_len; ++i) {
		gr = GP.sts[i].get_grades();
		s = 0;
		for (j = 0; j < 5; ++j) {
			s += gr[j];
		}
		if (s / 5 >= 4) {
			flag = true;
			os << "\t" << GP.sts[i];
		}
	}
	if (!flag) os << "\t\tempty!" << endl;
	return os;
}
std::istream& operator>>(std::istream& is, Group &GP) {
	Student st;
	cin >> st;
	GP += st;
	return is;
}