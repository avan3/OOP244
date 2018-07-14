#include "SavingsAccount.h" 

namespace sict {
	// define interest rate
   const double iRate = 0.05;

	// TODO: Allocator function
   iAccount* CreateAccount(const char* acc, double bal) {
      iAccount* account = nullptr;
      if (acc[0] == 'S') {
         account = new SavingsAccount(bal, iRate);
      }
      return account;
   }
}
