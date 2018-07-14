#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>

using namespace std;
namespace sict {
	const int max_rounds = 100;
	class Hero {
	private:
		char name[41];
		int health;
		int atkStr;
	public:
		Hero();
		Hero(const char *, int, int);
		bool isAlive() const;
		int attackStrength() const;
		void operator-=(int attack);
		friend ostream& operator<<(ostream& os, const Hero& hero);
	};
	const Hero& operator*(const Hero& first, const Hero& second);
}
#endif