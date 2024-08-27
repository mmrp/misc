all: out/libtest.so out/prg

deps:
	mkdir -p out

clean:
	rm -rf out

out/libtest.so: test.cpp
	g++ -fPIC -o out/test.o -c test.cpp -std=c++2a
	g++ -shared -o $@ out/test.o 

out/prg: main.c
	gcc -o $@ $^
