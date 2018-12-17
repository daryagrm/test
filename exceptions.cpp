#include <iostream>
#include "exceptions.h"

using std::cout;
using std::cin;
using std::endl;
exceptions::exceptions() : mesg(nullptr) {
	cout << "\t" << "exceptions()" << endl;
}
exceptions::exceptions(const char* s) {
	cout << "\t" << "exceptions(...)" << endl;
	int n = _strlen(s);
	
		mesg = nullptr;
	if (n++) {
		mesg = new char[n];
		_strcpy(mesg, s, n);
	}
}
exceptions::exceptions(exceptions &e) {
	cout << "\t" << "exceptions(exceptions&)" << endl;
	int n = _strlen(e.mesg) + 1;
	mesg = new char[n];
	_strcpy(mesg, e.mesg, n);
}
exceptions::exceptions(exceptions &&e) {
	cout << "\t" << "exceptions(exceptions&&)" << endl;
	mesg = e.mesg;
	e.mesg = nullptr;
}
exceptions::~exceptions() {
	cout << "\t" << "~exceptions()" << endl;
	delete[] mesg;
}
const char* exceptions::what() {
	return mesg;
}