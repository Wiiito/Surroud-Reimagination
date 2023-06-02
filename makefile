all: compile link delete run

compile:
	g++ -c main.cpp src/*.cpp

link:
	g++ *.o -o main -lsfml-graphics -lsfml-window -lsfml-system

run:
	./main

delete:
	rm -rf *.o