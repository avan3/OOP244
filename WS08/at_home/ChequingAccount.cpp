// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include <iomanip>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	ChequingAccount::ChequingAccount(double bal, double tFee, double mFee) : Account(bal) {
		transFee = 0;
		monthFee = 0;
		if (tFee > 0) {
			transFee = tFee;
		}
		if (mFee > 0) {
			monthFee = mFee;
		}
	}


	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	bool ChequingAccount::credit(double bal) {
		if (Account::credit(bal)) {
			Account::debit(transFee);
			return true;
		}
		return false;
	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	bool ChequingAccount::debit(double bal) {
		if (Account::debit(bal)) {
			Account::debit(transFee);
			return true;
		}
		return false;
	}

	// monthEnd debits month end fee
	void ChequingAccount::monthEnd() {
		ChequingAccount::debit(monthFee);
	}


	// display inserts account information into ostream os
	void ChequingAccount::display(std::ostream& ostr) const {
		ostr << "Account type: Chequing" << std::endl;
		ostr << "Balance: $" << std::fixed << std::setprecision(2) << balance() << std::endl;
		ostr << "Per Transaction Fee: " << std::fixed << std::setprecision(2) << transFee << std::endl;
		ostr << "Monthly Fee: " << std::fixed << std::setprecision(2) << monthFee << std::endl;
	}
}