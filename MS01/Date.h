// Final Project Milestone 1
//
// Version 1.0
// Date: June 27, 2018
// Author: Andrew Van
// Description: OOP244 Section B
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef AMA_DATE_H
#define AMA_DATE_H

// MACROS
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

#include <iostream>

namespace AMA {
   const int min_year = 2000;
   const int max_year = 2030;

   class Date {
      int year;
      int month;
      int day;
      int comparator;
      int errorState;
      int mdays(int, int) const;
      void errCode(int);
   public:
      // Constructors
      Date();
      Date(int, int, int);
      // Operators
      bool operator==(const Date&) const;
      bool operator!=(const Date&) const;
      bool operator<(const Date&) const;
      bool operator>(const Date&) const;
      bool operator<=(const Date&) const;
      bool operator>=(const Date&) const;
      // Queries and Modifiers
      int errCode() const;
      bool bad() const;
      std::istream& read(std::istream& istr);
      std::ostream& write(std::ostream& ostr) const;
   };
   // Helper Functions
   std::ostream& operator<<(std::ostream& ostr, const Date&);
   std::istream& operator>>(std::istream& istr, Date&);
}
#endif