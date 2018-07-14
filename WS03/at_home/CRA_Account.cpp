//--------------------------------------------------
// Name: Andrew Van      
// Student Number: 141267179
// Email: avan3@myseneca.ca 
// Section: SBB       
// Workshop: 3     
//--------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "CRA_Account.h"

using namespace std;
using namespace sict;

CRA_Account::CRA_Account() {
   strncpy(fName, "", max_name_length);
   strncpy(gName, "", max_name_length);
   SIN = 0;
   rYear[max_yrs] = {0};
   orBalance[max_yrs] = {0};
}

CRA_Account::~CRA_Account() {
}

void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
   int i;
   if (isEmpty() == true) {
      if (isValid(sin) && familyName[0] != '\0' && givenName[0] != '\0') {
         for (i = 0; i < max_name_length; i++) {
            fName[i] = familyName[i];
            gName[i] = givenName[i];
         }
         SIN = sin;
         years = 0;
      }
      else {
         strncpy(fName, "", max_name_length);
         strncpy(gName, "", max_name_length);
         SIN = 0;
      }
   }
}

bool CRA_Account::isEmpty() const {
   if (SIN == 0 || fName == "" || gName == "") {
      return true;
   }
   return false;
}

void CRA_Account::display() const {
	int i;
	if (isEmpty() == true) {
      cout << "Account object is empty!" << endl;
	}
	else {
      cout << "Family Name: " << fName << endl;
      cout << "Given Name : " << gName << endl;
      cout << "CRA Account: " << SIN << endl;
	  for (i = 0; i < years; i++) {
		  if (orBalance[i] > 2) {
			  cout << "Year (" << rYear[i] << ") balance owing: " << fixed << setprecision(2) << abs(orBalance[i]) << endl;
		  }
		  else if (orBalance[i] < -2) {
			  cout << "Year (" << rYear[i] << ") refund due: " << fixed << setprecision(2) << abs(orBalance[i]) << endl;
		  }
		  else {
			  cout << "Year (" << rYear[i] << ") No balance owing or refund due!" << endl;
		  }
	  }
	}
}
void CRA_Account::set(int year, double balance) {
   if (SIN && years < max_yrs) {
      rYear[years] = year;
      orBalance[years] = balance;
	  years++;
   }
}

bool CRA_Account::isValid(int sin) const {
   int check;
   int i;
   int digit;
   int fSum = 0;
   int sSum = 0;
   int tSum = 0;
   float hMultiple;

   // Check if sin is within parameters
   if (sin <= max_sin && sin >= min_sin) {
      // Take last digit of sin, remove it from sin and store it in check
	  check = sin % 10;
      sin = sin / 10;
      for (i = 0; i < 8; i++) {
         if (i % 2 == 0) { // Take every even position digit
            digit = sin % 10; // Store single digit into array
            digit += digit; // Double the stored digit
            sin = sin / 10; // Move onto next digit
			// Add each single digit to fSum. Doubled digit cannot be greater than 18 so do it twice
            fSum += digit % 10;
            digit /= 10; 
            fSum += digit;
         }
         else {
			// Take every odd position digit and add it to sSum
            digit = sin % 10;
            sin = sin /10;
            sSum += digit;
         }
      }
      tSum = fSum + sSum; // Add two sums together
	  // Calculate the next highest multiple of 10 for the tSum
      hMultiple = ceil((float)tSum/10)*10;
	  // Check if subtraction of multiple by tSum is equal to check which we removed earlier 
      if (hMultiple - tSum == check) {
         return true;
      }
      else {
         return false;
      }
   }
   else {
      return false;
   }
}