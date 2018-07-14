#include <iomanip>
#include "SavingsAccount.h"

namespace sict {
   SavingsAccount::SavingsAccount(double bal, double rate) : Account(bal) {
      if (rate > 0) {
         iRate = rate;
      }
   }
   
   void SavingsAccount::monthEnd() {
      double interest = (balance() * iRate);
      credit(interest);
   }

   void SavingsAccount::display(std::ostream& ostr) const {
      ostr << "Account type: Savings" << std::endl;
      ostr << "Balance: $" << std::fixed << std::setprecision(2) << balance() << std::endl;
      ostr << "Interest Rate (%): " << std::fixed << std::setprecision(2) << iRate << std::endl;
   }
}