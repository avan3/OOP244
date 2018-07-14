#include "SuperHero.h"

namespace sict {
   // Constructors:
   SuperHero::SuperHero() {
      bonus = 0;
      defStr = 0;
   }

   SuperHero::SuperHero(const char * n, int h, int a, int b, int d) : Hero(n, h, a) {
      if (b > 0 && d > 0) {
         bonus = b;
         defStr = d;
      }
      else {
         *this = SuperHero();
      }
   }

   // Other member functions:
   int SuperHero::attackStrength() const {
      if (this->isAlive() == false) {
         return 0;
      }
      int attackStrength = Hero::attackStrength();
      return (attackStrength + this->bonus);
   }

   int SuperHero::defend() const {
      if (defStr == 0) {
         return 0;
      }
      return defStr;
   }
   // Non-friend member function:
   const SuperHero& operator*(const SuperHero& first, const SuperHero& second) {
      SuperHero f = first;
      SuperHero s = second;
      int damageF = (f.attackStrength() - s.defend());
      int damageS = (s.attackStrength() - f.defend());
      int i; 
      for (i = 0; i < max_rounds && f.isAlive() == true && s.isAlive() == true; i++) {
         f -= damageS;
         s -= damageF;
      }
      if (f.isAlive() == true) {
         cout << "Super Fight! " << first << " vs " << second << " : Winner is " << first << " in " << i << " rounds." << endl;
         return first;
      }
      else {
         cout << "Super Fight! " << first << " vs " << second << " : Winner is " << second << " in " << i << " rounds." << endl;
         return second;
      }
   }
}