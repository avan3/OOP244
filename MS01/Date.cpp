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
   Date::Date() {
      year = 0;
      month = 0;
      day = 0;
      comparator = 0;
      errorState = NO_ERROR;
   }

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
   int Date::errCode() const {
      return errorState;
   }

   bool Date::bad() const {
      if (errorState != 0) {
         return true;
      }
      return false;
   }

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
