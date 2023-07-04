all: compile link run

compile:
	g++ -c main.cpp src/*.cpp -ISFML/include

link:
	g++ *.o -o main.exe -LSFML/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	./main.exe