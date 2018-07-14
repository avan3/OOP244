// TODO: add file header comments here
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
// TODO: add your headers here
#include "Passenger.h"
// TODO: continue your namespace here
using namespace std;
using namespace sict;
    // TODO: implement the default constructor here
Passenger::Passenger() {
   oName[0] = '\0';
   destination[0] = '\0'; 
   year = 0;
   month = 0;
   day = 0;
}
	// TODO: implement the constructor with 2 parameters here
Passenger::Passenger(const char * pName, const char * pDestination) {
   if (pName == nullptr || pDestination == nullptr || pName == '\0' || pDestination == '\0') {
	   *this = Passenger();
   }
   else {
	   strncpy(oName, pName, 32);
	   strncpy(destination, pDestination, 32);
	   year = 2017;
	   month = 07;
	   day = 1;
   }
}

// Constructor with 5 parameters
Passenger::Passenger(const char * pName, const char * pDestination, int pYear, int pMonth, int pDay) {
	if (pName == nullptr || pDestination == nullptr || pName[0] == '\0' || pDestination[0] == '\0' || pYear < 2017 || pYear > 2020 || pMonth < 1 || pMonth > 12 || pDay < 1 || pDay > 31) {
		*this = Passenger();
	}
	else {
		strncpy(oName, pName, 32);
		strncpy(destination, pDestination, 32);
		year = pYear;
		month = pMonth;
		day = pDay;
	}
}
    // TODO: implement isEmpty query here
bool Passenger::isEmpty() const {
	if (oName[0] == '\0' || destination[0] == '\0' || year == 0 || month == 0 || day == 0) {
      return true;
   }
   return false;
}
    // TODO: implement display query here
void Passenger::display() const {
	if (isEmpty() == true) {
		cout << "No passenger!" << endl;
	}
	else {
		cout << oName << " - " << destination << " on " << year << "/0" << month << "/" << day << endl;
	}
}

// Query for address of the name of the passenger
const char* Passenger::name() const {
	return this->oName;
}

// Query for canTravelWith
bool Passenger::canTravelWith(const Passenger& travelPartner) {
	if (*this->destination == *travelPartner.destination && this->day == travelPartner.day && this->month == travelPartner.month && this->year == travelPartner.year) {
		return true;
	}
	else {
		return false;
	}
}