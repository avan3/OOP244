// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#include <iomanip>
#include "Date.h"
namespace AMA {

   // Constructors:
   // Set Date object to safe empty state
   Date::Date() {
      year = 0;
      month = 0;
      day = 0;
      comparator = 0;
      errorState = NO_ERROR;
   }

   // Set Date object to arguments given following validation
   Date::Date(int y, int m, int d) {
      if (y < min_year || y > max_year) {
         *this = Date();
         errCode(YEAR_ERROR);
      }
      else if (m < 1 || m > 12) {
         *this = Date();
         errCode(MON_ERROR);
      }
      else if (mdays(m, y) < d) {
         *this = Date();
         errCode(DAY_ERROR);
      }
      else {
         errCode(NO_ERROR);
         year = y;
         month = m;
         day = d;
         comparator = year * 372 + month * 13 + day;
      }
   }
  // number of days in month mon_ and year year_
  //
  int Date::mdays(int mon, int year) const {
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int month = mon >= 1 && mon <= 12 ? mon : 13;
    month--;
    return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
   // Check and set the error code 
  void Date::errCode(int errorCode) {
      switch (errorCode) {
         case NO_ERROR:
            errorState = errorCode;
         case CIN_FAILED:
            errorState = errorCode;
         case YEAR_ERROR:
            errorState = errorCode;
         case MON_ERROR:
            errorState = errorCode;
         case DAY_ERROR:
            errorState = errorCode;
      }
   }

   // Operators:
   // Each operator function checks if object is in safe empty state 
   // Then checks the comparator value between the lhs and rhs
   bool Date::operator==(const Date& rhs) const {
      if (year != 0 && bad() == false) {
         if (comparator == rhs.comparator) {
            return true;
         }
      }
      return false;
   }
   
   bool Date::operator!=(const Date& rhs) const {
      if (year != 0 && bad() == false) {
         if (comparator != rhs.comparator) {
            return true;
         }
      }
      return false;
   }

   bool Date::operator<(const Date& rhs) const {
      if (year != 0 && bad() == false) {
         if (comparator < rhs.comparator) {
            return true;
         }
      }
      return false;
   }

   bool Date::operator>(const Date& rhs) const {
      if (year != 0 && bad() == false) {
         if (comparator > rhs.comparator) {
            return true;
         }
      }
      return false;
   }

   bool Date::operator<=(const Date& rhs) const {
      if (year != 0 && bad() == false) {
         if (comparator <= rhs.comparator) {
            return true;
         }
      }
      return false;
   }

   bool Date::operator>=(const Date& rhs) const {
      if (year != 0 && bad() == false) {
         if (comparator >= rhs.comparator) {
            return true;
         }
      }
      return false;
   }

   // Queries and modifier
   // Query for ErrorState object
   int Date::errCode() const {
      return errorState;
   }

   // Query for state of the ErrorState object
   bool Date::bad() const {
      if (errorState != 0) {
         return true;
      }
      return false;
   }

   // Read the date on the specified format (i.e. YYYY/MM/DD)
   std::istream& Date::read(std::istream& istr) {
      int y;
      int m;
      int d;
      char slash;
      istr >> y >> slash >> m >> slash >> d;
      if (istr.fail() == true) {
         errorState = CIN_FAILED;
      }
      else {
         *this = Date(y,m,d);
      }
      return istr;
   }

   // Write year according to the specified format and fill the extra space of Month and Day with 0
   std::ostream & Date::write(std::ostream& ostr) const {
      ostr << year << "/" 
      << std::setw(2) << std::setfill('0') << month << "/"
      << std::setw(2) << std::setfill('0') << day;
      return ostr;
   }
   // Helper Functions
   std::ostream & operator<<(std::ostream & ostr, const Date& d) {
      d.write(ostr);
      return ostr;
   }

   std::istream& operator>>(std::istream& istr, Date& d) {
      d.read(istr);
      return istr;
   }
}
