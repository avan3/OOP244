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
		Contact& operator=(const Contact&);
		int getLength(long long) const;
		int getValid(const long long *, int);
	public:
		Contact();
		Contact(const char *, const long long *, int);
		~Contact();
		bool isEmpty() const;
		void display() const;
	};
}

#endif