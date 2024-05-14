cc="g++"
flags="-g3"

build: *.cpp
	$(cc) *.cpp -o run
debug: *.cpp
	$(cc) *.cpp $(flags) -o debug
