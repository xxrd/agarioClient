#include "util.h"

int random(int a, int b) {
	if (a > 0) return a + rand() % (b - a);
	else return a + rand() % (std::abs(a) + b);
}

float massToRadius(float mass) {
	return 4 + sqrt(mass) * 6;
}

float randomInRange(float from, float to) {
	return random(from, to);
}

float vectorLength(float x, float y) {
	return sqrt(pow(x, 2) + pow(y, 2));
}