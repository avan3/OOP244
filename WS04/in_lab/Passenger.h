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
      char name[32];
      char destination[32];
   public:
      Passenger();
      Passenger(const char *, const char *);
      bool isEmpty() const;
      void display() const;
   };
}
#endif