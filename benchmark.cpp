#include <stdlib.h>
#include <stdint.h>
#include <cmath>

#include <benchmark/benchmark.h>

#ifdef __GNUG__
#define __builtin_assume(c) if(!(c)) { __builtin_unreachable(); }
#endif

static int32_t factorial_basic(int32_t n) {
    if(n <= 0) [[unlikely]] return 1;
    return n * factorial_basic(n-1);
}

consteval int32_t f(int32_t n) {
    if(n <= 0) [[unlikely]] return 1;
    return n * f(n-1);
}

#define X(n) case n: return f(n)
static int32_t factorial_lookup_table_switch(int32_t n) {
    switch(n) {
        X(0);
        X(1);
        X(2);
        X(3);
        X(4);
        X(5);
        X(6);
        X(7);
        X(8);
        X(9);
        X(10);
        X(11);
        X(12);
        default: __builtin_unreachable();
    }
}

#define Y(x) if(n == x) v = f(x)
static int32_t factorial_lookup_table_cmov(int32_t n) {
	int32_t v;
	Y(0);
	Y(1);
	Y(2);
	Y(3);
	Y(4);
	Y(5);
	Y(6);
	Y(7);
	Y(8);
	Y(9);
	Y(10);
	Y(11);
	Y(12);
	return v;
}

static int32_t factorial_branchless_0(int32_t n) {
    __builtin_assume(n >= 0);
    __builtin_assume(n <= 12);
    int32_t a = 1, b = 1, c = 1, d = 1, e = 1, f = 1, g = 1, h = 1, i = 1, j = 1, k = 1;
    if(n >= 2)  a = 2;
    if(n >= 3)  b = 3;
    if(n >= 4)  c = 4;
    if(n >= 5)  d = 5;
    if(n >= 6)  e = 6;
    if(n >= 7)  f = 7;
    if(n >= 8)  g = 8;
    if(n >= 9)  h = 9;
    if(n >= 10) i = 10;
    if(n >= 11) j = 11;
    if(n >= 12) k = 12;
    return a * b * c * d * e * f * g * h * i * j * k;
}

static int32_t factorial_branchless_1(int32_t n) {
    int32_t a = 1;
    for(int32_t i = 2; i < 13; i++) {
        int32_t q = 1;
        if(i <= n) {
            q = i;
        }
        a *= q;
    }
    return a;
}

constexpr double pi = 3.14159265358979323846;
constexpr double E = 2.71828182845904523536;
constexpr double twopi = 2 * pi;

static int32_t factorial_stirling(int32_t n) {
	// note: this isn't fantastic in terms of finding true performance because the calls to std::sqrt and std::pow are not inlined.
	return std::sqrt(twopi * n) * std::pow(n / E, n);
}

#define bench_fn(fn) static void bench_##fn(benchmark::State& state) { \
	for (auto _ : state) { \
		int32_t n = rand() % 13; \
		benchmark::DoNotOptimize(fn(n)); \
	} \
} \
BENCHMARK(bench_##fn)

bench_fn(factorial_basic);
bench_fn(factorial_lookup_table_switch);
bench_fn(factorial_lookup_table_cmov);
bench_fn(factorial_branchless_0);
bench_fn(factorial_branchless_1);
bench_fn(factorial_stirling);

static int64_t factorial_basic_64(int64_t n) {
    if(n <= 0) [[unlikely]] return 1;
    return n * factorial_basic_64(n-1);
}

consteval int64_t f_64(int64_t n) {
    if(n <= 0) [[unlikely]] return 1;
    return n * f_64(n-1);
}

#undef X
#define X(n) case n: return f_64(n)
static int64_t factorial_lookup_table_64_switch(int64_t n) {
    switch(n) {
        X(0);
        X(1);
        X(2);
        X(3);
        X(4);
        X(5);
        X(6);
        X(7);
        X(8);
        X(9);
        X(10);
        X(11);
        X(12);
        X(13);
        X(14);
        X(15);
        X(16);
        X(17);
        X(18);
        X(19);
        X(20);
        default: __builtin_unreachable();
    }
}

#undef Y
#define Y(x) if(n == x) v = f_64(x)
static int64_t factorial_lookup_table_64_cmov(int64_t n) {
	int64_t v;
	Y(0);
	Y(1);
	Y(2);
	Y(3);
	Y(4);
	Y(5);
	Y(6);
	Y(7);
	Y(8);
	Y(9);
	Y(10);
	Y(11);
	Y(12);
	Y(13);
	Y(14);
	Y(15);
	Y(16);
	Y(17);
	Y(18);
	Y(19);
	Y(20);
	return v;
}

static int64_t factorial_branchless_0_64(int64_t _n) {
    __builtin_assume(_n >= 0);
    __builtin_assume(_n <= 20);
    int64_t a = 1, b = 1, c = 1, d = 1, e = 1, f = 1, g = 1, h = 1, i = 1, j = 1, k = 1, l = 1,
	        m = 1, n = 1, o = 1, p = 1, q = 1, r = 1, s = 1;
    if(_n >= 2)  a = 2;
    if(_n >= 3)  b = 3;
    if(_n >= 4)  c = 4;
    if(_n >= 5)  d = 5;
    if(_n >= 6)  e = 6;
    if(_n >= 7)  f = 7;
    if(_n >= 8)  g = 8;
    if(_n >= 9)  h = 9;
    if(_n >= 10) i = 10;
    if(_n >= 11) j = 11;
    if(_n >= 12) k = 12;
    if(_n >= 13) l = 13;
    if(_n >= 14) m = 14;
    if(_n >= 15) n = 15;
    if(_n >= 16) o = 16;
    if(_n >= 17) p = 17;
    if(_n >= 18) q = 18;
    if(_n >= 19) r = 19;
    if(_n >= 20) s = 20;
    return a * b * c * d * e * f * g * h * i * j * k * l * m * n * o * p * q * r * s;
}

static int64_t factorial_branchless_1_64(int64_t n) {
    int64_t a = 1;
    for(int64_t i = 2; i < 21; i++) {
        int64_t q = 1;
        if(i <= n) {
            q = i;
        }
        a *= q;
    }
    return a;
}

#undef bench_fn
#define bench_fn(fn) static void bench_##fn(benchmark::State& state) { \
	for (auto _ : state) { \
		int32_t n = rand() % 21; \
		benchmark::DoNotOptimize(fn(n)); \
	} \
} \
BENCHMARK(bench_##fn)

bench_fn(factorial_basic_64);
bench_fn(factorial_lookup_table_64_switch);
bench_fn(factorial_lookup_table_64_cmov);
bench_fn(factorial_branchless_0_64);
bench_fn(factorial_branchless_1_64);

BENCHMARK_MAIN();
