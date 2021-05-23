benchmark:
	mkdir -p bin
	clang++-12 benchmark.cpp -O3 -std=c++20 -lbenchmark -lpthread -o bin/benchmark -Wall -flto
	g++-11 benchmark.cpp -O3 -std=c++20 -lbenchmark -lpthread -o bin/benchmark-gcc -Wall -flto

# create an assembly dump
benchmark.dump: benchmark.o
	objdump -d -M intel -S bin/benchmark.o > bin/benchmark.dump
benchmark.o:
	mkdir -p bin
	clang++-12 benchmark.cpp -O3 -std=c++20 -c -o bin/benchmark.o -g

factorial:
	mkdir -p bin
	clang++-12 experiments/factorial.cpp -O3 -std=c++20 -o bin/factorial
