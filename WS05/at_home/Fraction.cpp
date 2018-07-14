//--------------------------------------------------
// Name: Andrew Van      
// Student Number: 141267179
// Email: avan3@myseneca.ca 
// Section: SBB       
// Workshop: 5
//--------------------------------------------------
// TODO: insert header files
#include <iostream>
#include <cmath>
#include "Fraction.h"
// TODO: continue the namespace
using namespace std;
using namespace sict;
	// TODO: implement the default constructor
Fraction::Fraction() {
   numerator = 0;
   denominator = 0;
   fraction = 0;
   }
	// TODO: implement the two-argument constructor
Fraction::Fraction(int num, int den) {
   if (num >= 0 && den > 0) {
      numerator = num;
      denominator = den;
      reduce();
   }
   else {
      *this = Fraction();
   }
}
	// TODO: implement the max query
int Fraction::max() const {
   if (numerator >= denominator) {
      return numerator;
   }
   else {
      return denominator;
   }
}
    // TODO: implement the min query
int Fraction::min() const {
   if (numerator < denominator) {
      return numerator;
   }
   else {
      return denominator;
   }
}
	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
    void Fraction::reduce() {
      int greatCD = gcd();
      numerator /= greatCD;
      denominator /= greatCD;
   }

    // TODO: implement the display query
    void Fraction::display() const {
       if (isEmpty() == true) {
         cout << "no fraction stored";
      }
       else {
          if (numerator % denominator !=  0 && denominator != 1) {
            cout << numerator << "/" << denominator;
          }
          else {
             cout << numerator;
         }
      }
   }
    // TODO: implement the isEmpty query
    bool Fraction::isEmpty() const {
       if (denominator <= 0) {
          return true;
      }
      return false;
   }

    // TODO: implement the + operator
    Fraction Fraction::operator+(const Fraction & rhs) const {
       Fraction sum;
       if (this->isEmpty() == false && rhs.isEmpty() == false) {
         sum.numerator = (this->numerator*rhs.denominator) + (this->denominator*rhs.numerator);
         sum.denominator = (this->denominator*rhs.denominator);
         return sum;
       }
       else {
          return sum;
       }
    }

	// TODO: implement the * operator
	Fraction Fraction::operator*(const Fraction & rhs) const {
		Fraction product;
		if (this->isEmpty() == false && rhs.isEmpty() == false) {
			product.numerator = (this->numerator*rhs.numerator);
			product.denominator = (this->denominator*rhs.denominator);
			product.reduce();
			return product;
		}
		else {
			return product;
		}
	}

	// TODO: implement the == operator
	bool Fraction::operator==(const Fraction & rhs) const {
		if (this->isEmpty() == false && rhs.isEmpty() == false) {
			if (this->numerator == rhs.numerator && this->denominator == rhs.denominator) {
				return true;
			}
		}
		return false;
	}

	// TODO: implement the != operator
	bool Fraction::operator!=(const Fraction & rhs) const {
		if (this->isEmpty() == false && rhs.isEmpty() == false) {
			if (this->numerator != rhs.numerator && this->denominator != rhs.denominator) {
				return true;
			}
		}
		return false;
	}

	// TODO: implement the += operator
	Fraction& Fraction::operator+=(const Fraction & rhs) {
		if (this->isEmpty() == false && rhs.isEmpty() == false) {
			*this = *this + rhs;
		}
		else {
			*this = Fraction();
		}
		return *this;
	}