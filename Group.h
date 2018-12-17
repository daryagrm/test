#pragma once
#ifndef _GROUP_H_
#define _GROUP_H_

#include "Student.h"

#define freq 15

class Group {
public:
	Group();
	Group(const Student *st, int l);
	Group(const Group &GP);
	~Group();

	void operator+=(const Student &st);
	void operator-(int n);

	void show();
	bool empty();

	friend std::ostream& operator<<(std::ostream& os, const Group &GP);
	friend std::istream& operator>>(std::istream& is, Group &GP);
private:
	Student *sts;
	int st_len;
	int size;
	void init(
		const Student *st,
		int l,
		int s
	);
};

#endif