#pragma once

using namespace std;

template<class T>
class vec2 {
public:
	T x, y;
	vec2() :x(0), y(0) {}
	vec2(T x, T y) : x(x), y(y) {}
	vec2(const vec2& v) : x(v.x), y(v.y) {}

	vec2& operator=(const vec2& v) {
		x = v.x;
		y = v.y;
		return *this;
	}

	vec2 operator+(vec2& v) {
		return vec2(x + v.x, y + v.y);
	}

	vec2 operator-(vec2& v) {
		return vec2(x - v.x, y - v.y);
	}

	vec2& operator+=(vec2& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	vec2& operator-=(vec2& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	vec2 operator+(double s) {
		return vec2(x + s, y + s);
	}

	vec2 operator-(double s) {
		return vec2(x - s, y - s);
	}

	vec2 operator*(double s) {
		return vec2(x * s, y * s);
	}

	vec2 operator/(double s) {
		return vec2(x / s, y / s);
	}

	vec2& operator+=(double s) {
		x += s;
		y += s;
		return *this;
	}

	vec2& operator-=(double s) {
		x -= s;
		y -= s;
		return *this;
	}

	vec2& operator*=(double s) {
		x *= s;
		y *= s;
		return *this;
	}

	vec2& operator/=(double s) {
		x /= s;
		y /= s;
		return *this;
	}

	static float length(float x, float y) {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	float length() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	vec2& normalize() {
		if (length() == 0) return *this;
		*this *= (1.0 / length());
		return *this;
	}

	vec2& normalize(float minLength) {
		float len = length();
		len = len < minLength ? minLength : len;
		*this *= (1.0 / len);
		return *this;
	}
};