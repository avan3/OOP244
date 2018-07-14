//--------------------------------------------------
// Name: Andrew Van      
// Student Number: 141267179
// Email: avan3@myseneca.ca 
// Section: SBB       
// Workshop: 5
//--------------------------------------------------
// TODO: header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
#include <iostream>
// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
      int numerator;
      int denominator;
      double fraction;
		// TODO: declare private member functions

	public:
		// TODO: declare public member functions
      Fraction();
      Fraction(int, int);
      int max() const;
      int min() const;
      void reduce();
      int gcd() const;
      bool isEmpty() const;
      void display() const;
		// TODO: declare the + operator overload
      Fraction operator+(const Fraction& rhs) const;
	  Fraction operator*(const Fraction& rhs) const;
	  bool operator==(const Fraction& rhs) const;
	  bool operator!=(const Fraction& rhs) const;
	  Fraction& operator+=(const Fraction& rhs);
	};
}
#endif