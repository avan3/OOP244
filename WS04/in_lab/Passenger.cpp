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
   name[0] = '\0';
   destination[0] = '\0'; 
}
	// TODO: implement the constructor with 2 parameters here
Passenger::Passenger(const char * pName, const char * pDestination) {
   if (pName == nullptr || pDestination == nullptr || pName == '\0' || pDestination == '\0') {
	   name[0] = '\0';
	   destination[0] = '\0';
   }
   else {
	   strncpy(name, pName, 32);
	   strncpy(destination, pDestination, 32);
   }
}
    // TODO: implement isEmpty query here
bool Passenger::isEmpty() const {
   if (name[0] == '\0' || destination[0] == '\0') {
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
		cout << name << " - " << destination << endl;
	}
}
