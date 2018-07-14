//--------------------------------------------------
// Name: Andrew Van      
// Student Number: 141267179
// Email: avan3@myseneca.ca 
// Section: SBB       
// Workshop: 3     
//--------------------------------------------------
#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;
using namespace sict;

CRA_Account::CRA_Account() {
   strncpy(fName, "", max_name_length);
   strncpy(gName, "", max_name_length);
   SIN = 0;
}

CRA_Account::~CRA_Account() {
}

void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
	int i;
	if (isEmpty() == true) {
		for (i = 0; i < max_name_length; i++) {
			fName[i] = familyName[i];
			gName[i] = givenName[i];
		}
      if (sin <= max_sin && sin >= min_sin) {
         SIN = sin;
      }
	}
	else {
		SIN = 0;
	}
}

bool CRA_Account::isEmpty() const {
	if (SIN == 0) {
		return true;
	}
	return false;
}

void CRA_Account::display() const {
	if (SIN == 0) {
      cout << "Account object is empty!" << endl;
	}
	else {
      cout << "Family Name: " << fName << endl;
      cout << "Given Name : " << gName << endl;
      cout << "CRA Account: " << SIN << endl;
	}
}