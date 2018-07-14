#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <iomanip>
#include <cstring>
#include "Contact.h"

using namespace std;
using namespace sict;

Contact::Contact() {
	*name = '\0';
	phNumber = nullptr;
	size = 0;
}

Contact::Contact(const char * n, const long long * p, int s) {
	if (n == nullptr || *n == '\0') {
		*this = Contact();
	}
	else {
		int length = 0;
		int j = 0;
		int count = 0;
		strncpy(name, n, 19);
		name[19] = '\0';
		size = s;
		if (size > 0) {
			count = getValid(p, size);
			phNumber = new (nothrow) long long[count];
			for (int i = 0; i < size; i++) {
				length = getLength(p[i]);
				if (length == 11 || length == 12) {
					phNumber[j] = p[i];
					++j;
				}
			}
			size = count;
		}
		else {
			phNumber = nullptr;
		}
	}
}

Contact::~Contact() {
	delete[] phNumber;
	phNumber = nullptr;
}

bool Contact::isEmpty() const{
	if (name == nullptr || *name == '\0') {
		return true;
	}
	return false;
}

void Contact::display() const {
	if (isEmpty() == true) {
		cout << "Empty contact!" << endl;
	}
	else {
		Contact temp;
		int areaCode = 0;
		int fPhoneNum = 0;
		int lPhoneNum = 0;
		temp = *this;
		cout << name << endl;
		if (temp.phNumber != nullptr) {
			for (int i = 0; i < size; i++) {
				lPhoneNum = temp.phNumber[i] % 10000;
				temp.phNumber[i] /= 10000;
				fPhoneNum = temp.phNumber[i] % 1000;
				temp.phNumber[i] /= 1000;
				areaCode = temp.phNumber[i] % 1000;
				temp.phNumber[i] /= 1000;
				cout << "(+" << temp.phNumber[i] << ") " 
					<< areaCode << " " 
					<< setfill('0') << setw(3) << fPhoneNum << "-" 
					<< setfill('0') << setw(4) << lPhoneNum << endl;
			}
		}
	}
}

Contact& Contact::operator=(const Contact& src) {
	if (this != &src) {
		strncpy(name, src.name, 19);
		name[19] = '\0';
		size = src.size;
		if (src.phNumber != nullptr) {
			phNumber = new (nothrow) long long[size];
			for (int i = 0; i < size; i++) {
				phNumber[i] = src.phNumber[i];
			}
		}
		else {
			phNumber = nullptr;
		}
	}
	return *this;
}

Contact::Contact(const Contact& src) {
	phNumber = nullptr;
	*this = src;
}

Contact& Contact::operator+=(const long long p) {
	int length = getLength(p);
	if (length == 11 || length == 12) {
		Contact tmp = *this;
		delete[] phNumber;
		phNumber = new (nothrow) long long[size+1];
		if (tmp.phNumber != nullptr) {
			for (int i = 0; i < tmp.size; i++) {
				phNumber[i] = tmp.phNumber[i];
			}
		}
		phNumber[size] = p;
		size++;
	}
	return *this;
}
// Private member functions:
int Contact::getLength(long long ph) const{
	int length = 0;
	while (ph) {
		ph /= 10;
		length++;
	}
	return length;
}

int Contact::getValid(const long long * ph, int size) {
	int length = 0;
	int count = 0;
	for (int i = 0; i < size; i++) {
		length = getLength(ph[i]);
		if (length == 11 || length == 12) {
			count++;
		}
	}
	return count;
}