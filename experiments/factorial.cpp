// Code bowled factorial implementation
// Collab between horrible clang codegen and myself
// Jeremy Rifkin 2021
// Thanks to @easyaspi314 for his help with debugging

#include <initializer_list>

template<typename T> struct V4 {
	T v[4];
	V4() = default;
	V4(std::initializer_list<T> l) { int i = 0; for(T x : l) v[i++] = x; }
	static V4 of(int n) {
		return V4 {n, n, n, n};
	}
	V4 operator+(const V4& other) const {
		V4 copy = *this;
		for(int i = 0; i < 4; i++) copy.v[i] += other.v[i];
		return copy;
	}
	V4 operator*(const V4& other) const {
		V4 copy = *this;
		for(int i = 0; i < 4; i++) copy.v[i] *= other.v[i];
		return copy;
	}
	V4 operator+=(const V4& other) {
		return *this = *this + other;
	}
	V4 operator*=(const V4& other) {
		return *this = *this * other;
	}
	T reduce() const {
		return v[0] * v[1] * v[2] * v[3];
	}
};

int factorial(int n) {
	int _69 = n;
	int _67 = 1;
	if(n >= 8) {
		int _6 = n & -8;
		int _11 = _6 - 8;
		int _13 = (_11 >> 3) + 1;
		int _14 = _13 & 3;
		V4<int> _60;
		V4<int> _61;
		V4<int> _44 = V4<int>::of(n) + V4{0, -1, -2, -3};
		V4<int> _45 = V4<int>::of(1);
		V4<int> _46 = V4<int>::of(1);
		if((unsigned)_11 >= 24) {
			int _22 = _13 & 1073741820;
			_60 = V4<int>::of(1);
			_61 = V4<int>::of(1);
			do {
				V4<int> _23 = _44 + V4<int>::of(-4);
				V4<int> _24 = _44 * _60;
				V4<int> _25 = _23 * _61;
				V4<int> _26 = _44 + V4<int>::of(-8);
				V4<int> _27 = _44 + V4<int>::of(-12);
				V4<int> _28 = _26 * _24;
				V4<int> _29 = _27 * _25;
				V4<int> _30 = _44 + V4<int>::of(-16);
				V4<int> _31 = _44 + V4<int>::of(-20);
				V4<int> _32 = _30 * _28;
				V4<int> _33 = _31 * _29;
				V4<int> _34 = _44 + V4<int>::of(-24);
				V4<int> _35 = _44 + V4<int>::of(-28);
				_60 = _34 * _32;
				_61 = _35 * _33;
				_44 += V4<int>::of(-32);
				_22 -= 4;
			} while(_22 != 0);
			_45 = _60;
			_46 = _61;
		}
		if(_14 != 0) {
			_60 = _45;
			do {
				_60 *= _44;
				_46 *= _44 + V4<int>::of(-4);
				_44 += V4<int>::of(-8);
			} while(--_14 != 0);
			_61 = _46;
		}
		_67 = (_61 * _60).reduce();
		if(_6 == n) {
			return _67;
		}
		_69 = n & 7;
	}
	if(n <= 0) return 1;
	do {
		_67 *= _69;
	} while(--_69 != 0);
	return _67;
}

#include <stdio.h>

int f(int n) {
	if(n <= 0) return 1;
	return n * f(n-1);
}

int main() {
	for(int i = 0; i <= 40; i++) {
		int a = factorial(i);
		int b = f(i);
		printf("%d %d %d\n", i, a == b, a);
	}
	return 0;
}
