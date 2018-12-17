#include <iostream>
#include "string.h"
using namespace std;

int _strlen(const char* s) {
	int i = 0;
	if (s) while (s[i] != '\0') ++i;
	return i;
}
void _strcpy(char *s1, const char* s2, int n) {
	for (int i = 0; i < n; ++i)
		s1[i] = s2[i];
}
bool _strcmp(const char *s1, const char* s2) {
	int i;
	int len = min(_strlen(s1), _strlen(s2));
	for (i = 0; i < len; ++i)
		if (s1[i] != s2[i]) return false;
	if (s1[i] != s2[i]) return false;
	return true;
}
char* read(const char *s) {
	int i;
	char *ptr;
	char c[MAX_SIZE];
	cout << s;
	for (i = 0; ((c[i] = std::cin.get()) != '\n'); ++i);
	c[i] = '\0';
	ptr = new char[i + 1];
	do {
		ptr[i] = c[i];
	} while (i--);
	return ptr;
}