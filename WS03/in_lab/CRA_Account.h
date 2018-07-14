//--------------------------------------------------
// Name: Andrew Van      
// Student Number: 141267179
// Email: avan3@myseneca.ca 
// Section: SBB       
// Workshop: 3     
//--------------------------------------------------
#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H

namespace sict {
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	class CRA_Account {
	private:
		char fName[max_name_length];
		char gName[max_name_length];
		int SIN;
	public:
      CRA_Account();
      ~CRA_Account();
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}
#endif
