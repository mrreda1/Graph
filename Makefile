cc=g++
flags=-Og -ggdb

build: *.cpp
	$(cc) *.cpp -o run
debug: *.cpp
	$(cc) *.cpp $(flags) -o debug
