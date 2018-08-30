.PHONY: clean all
all: main

main: main.o 1.o
	g++ $^ -o $@

%.o: %.cpp
	g++ -c $< -o $@

clean:
	rm -rf *.o main
