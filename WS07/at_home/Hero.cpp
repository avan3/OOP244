#include <cstring>
#include "Hero.h"

namespace sict {
	// Constructors:
	Hero::Hero() {
		// Empty State:
		*name = '\0';
		health = 0;
		atkStr = 0;
	}

	Hero::Hero(const char * n, int h, int a) {
		if (h > 0 || a > 0) {
			strncpy(name, n, 41);
			name[41] = '\0';
			health = h;
			atkStr = a;
		}
		else {
			*this = Hero();
		}
	}

	// Other public member functions:
	bool Hero::isAlive() const {
		if (health > 0) {
			return true;
		}
		return false;
	}

	int Hero::attackStrength() const {
		if (health <= 0) {
			return 0;
		}
		return atkStr;
	}

	void Hero::operator-=(int attack) {
		if (attack > 0) {
			health -= attack;
		}
		if (health < 0) {
			health = 0;
		}
	}

	// Helper functions:
	ostream& operator<<(ostream& os, const Hero& hero) {
		if (hero.name == '\0') {
			os << "No hero" << endl;
		}
		else {
			os << hero.name;
		}
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second) {
		Hero f = first;
		Hero s = second;
		int i;
		for (i = 0; i < max_rounds && f.isAlive() == true && s.isAlive() == true; i++) {
			f -= s.attackStrength();
			s -= f.attackStrength();
		}
		if (f.isAlive() == true) {
			cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << first << " in " << i << " rounds." << endl;
			return first;
		}
		else {
			cout << "Ancient Battle! " << first << " vs " << second << " : Winner is " << second << " in " << i << " rounds." << endl;
			return second;
		}
	}
}