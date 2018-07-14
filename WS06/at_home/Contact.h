#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H
#include <iostream>

using namespace std;

namespace sict {
	class Contact {
	private:
		char name[20];
		long long * phNumber;
		int size;
		int getLength(long long) const;
		int getValid(const long long *, int);
	public:
		Contact();
		Contact(const char *, const long long *, int);
		Contact(const Contact&);
		~Contact();
		Contact& operator=(const Contact&);
		Contact& operator+=(const long long);
		bool isEmpty() const;
		void display() const;
	};
}

#endif