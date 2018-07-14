// TODO: add file header comments here
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
// TODO: declare your namespace here
namespace sict {
    // TODO: define the Passenger class here
   class Passenger {
	   char oName[32];
	   char destination[32];
	   int year;
	   int month;
	   int day;
   public:
      Passenger();
      Passenger(const char *, const char *);
	  Passenger(const char *, const char *, int, int, int);
      bool isEmpty() const;
      void display() const;
	  const char* name() const;
	  bool canTravelWith(const Passenger &);
   };
}
#endif