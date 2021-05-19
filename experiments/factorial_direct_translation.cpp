// Surface-level translation from LLVM's IR to C++

#include <initializer_list>

template<typename T> struct V4 {
	T v[4];
	V4() = delete;
	V4(T a, T b, T c, T d) : v {a, b, c, d} {}
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
	T reduce_mul_v4i32() const {
		return v[0] * v[1] * v[2] * v[3];
	}
};

int factorial(int n) {
	if(n <= 0) { // label 74
		return 1;
	} else { // label 3:
		int _66 = n;
		int _67 = 1;
		bool _4 = n < 8;
		if(!_4) {
			// label 5
			int _6 = n & -8;
			int _7 = n & 7;
			V4<int> _9 = {n, n, n, n};
			V4<int> _10 = _9 + V4<int> {0, -1, -2, -3};
			int _11 = _6 - 8;
			int _12 = _11 >> 3;
			int _13 = _12 + 1;
			int _14 = _13 & 3;
			int _15 = (unsigned)_11 < 24;
			// phis
			V4<int> _42 = V4<int>::of(-1); // undef
			V4<int> _43 = V4<int>::of(-1); // undef
			V4<int> _44 = _10;
			V4<int> _45 = V4<int>::of(1);
			V4<int> _46 = V4<int>::of(1);
			if(!_15) { // label 16
				int _17 = _13 & 1073741820;
				// phis
				V4<int> _19 = _10;
				V4<int> _20 = V4<int>::of(1);
				V4<int> _21 = V4<int>::of(1);
				int _22 = _17;
				bool _40;
				V4<int> _36 = V4<int>::of(-1); // uninit temporarily
				V4<int> _37 = V4<int>::of(-1); // uninit temporarily
				V4<int> _38 = V4<int>::of(-1); // uninit temporarily
				do {
					// label 18
					V4<int> _23 = _19 + V4<int>::of(-4);
					V4<int> _24 = _19 * _20;
					V4<int> _25 = _23 * _21;
					V4<int> _26 = _19 + V4<int>::of(-8);
					V4<int> _27 = _19 + V4<int>::of(-12);
					V4<int> _28 = _26 * _24;
					V4<int> _29 = _27 * _25;
					V4<int> _30 = _19 + V4<int>::of(-16);
					V4<int> _31 = _19 + V4<int>::of(-20);
					V4<int> _32 = _30 * _28;
					V4<int> _33 = _31 * _29;
					V4<int> _34 = _19 + V4<int>::of(-24);
					V4<int> _35 = _19 + V4<int>::of(-28);
					_36 = _34 * _32;
					_37 = _35 * _33;
					_38 = _19 + V4<int>::of(-32);
					int _39 = _22 - 4;
					_40 = _39 == 0;
					// phis
					_19 = _38;
					_20 = _36;
					_21 = _37;
					_22 = _39;
				} while(!_40);
				// phis
				_42 = _36;
				_43 = _37;
				_44 = _38;
				_45 = _36;
				_46 = _37;
			}
			// label 41
			bool _47 = _14 == 0;
			V4<int> _60 = _42;
			V4<int> _61 = _43;
			if(!_47) { // label 48
				bool _58;
				V4<int> _49 = _44;
				V4<int> _50 = _45;
				V4<int> _51 = _46;
				V4<int> _54 = V4<int>::of(-1); // unit, declared here for lifetime reasons
				V4<int> _55 = V4<int>::of(-1); // unit, declared here for lifetime reasons
				int _52 = _14;
				do {
					V4<int> _53 = _49 + V4<int>::of(-4);
					_54 = _49 * _50;
					_55 = _53 * _51;
					V4<int> _56 = _49 + V4<int>::of(-8);
					int _57 = _52 - 1;
					_58 = _57 == 0;
					_49 = _56;
					_50 = _54;
					_51 = _55;
					_52 = _57;
				} while(!_58);
				_60 = _54;
				_61 = _55;
			}
			// label 59
			V4<int> _62 = _61 * _60;
			int _63 = _62.reduce_mul_v4i32();
			bool _64 = _6 == n;
			if(_64) { // label 74
				return _63;
			}
			// phis
			_66 = _7;
			_67 = _63;
		}
		// label 65
		// blank
		// phis for 68
		int _69 = _66;
		int _70 = _67;
		bool _73;
		int _72;
		// label 68
		do {
			int _71 = _69 - 1;
			_72 = _69 * _70;
			_73 = _71 == 0;
			_69 = _71;
			_70 = _72;
		} while(!_73);
		// label 74
		return _72;
	}
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
