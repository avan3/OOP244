#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Hero.h"

namespace sict {
   class SuperHero : public Hero {
   private:
      int bonus;
      int defStr;
   public:
      SuperHero();
      SuperHero(const char *, int, int, int, int);
      int attackStrength() const;
      int defend() const;
   };
   const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}

#endif