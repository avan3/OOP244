#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {
	// define interest rate
   const double iRate = 5.00;
   const double transFee = 0.5;
   const double monthFee = 2.00;

	// TODO: Allocator function
   iAccount* CreateAccount(const char* acc, double bal) {
      iAccount* account = nullptr;
      if (acc[0] == 'S') {
         account = new SavingsAccount(bal, iRate);
      }
	  if (acc[0] == 'C') {
		  account = new ChequingAccount(bal, transFee, monthFee);
	  }
      return account;
   }
}
