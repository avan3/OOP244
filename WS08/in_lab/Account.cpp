#include "Account.h"

namespace sict {
   Account::Account(double bal) {
      if (bal > 0) {
         accBalance = bal;
      }
      else {
         accBalance = 0.0;
      }
   }

   bool Account::credit(double bal) {
      if (bal > 0) {
         accBalance += bal;
         return true;
      }
      return false;
   }

   bool Account::debit(double bal) {
      if (bal > 0) {
         accBalance -= bal;
         return true;
      }
      return false;
   }
   double Account::balance() const {
      return accBalance;
   }
}
