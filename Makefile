EXEC=snake
CXXFLAGS=-std=c++11 -g -Wall -Werror -pedantic -lncurses

$(EXEC): main.o Square.o Grid.o Snake.o Game.o CursesWindow.o
	g++  $^ -o $@ $(CXXFLAGS)

main.o: main.cpp Square.h general.h
	g++ -c $< -o $@ $(CXXFLAGS)

Square.o: Square.cpp Square.h
	g++ -c $< -o $@ $(CXXFLAGS)

Grid.o: Grid.cpp Grid.h
	g++ -c $< -o $@ $(CXXFLAGS)


Snake.o: Snake.cpp Snake.h
	g++ -c $< -o $@ $(CXXFLAGS)


Game.o: Game.cpp Game.h
	g++ -c $< -o $@ $(CXXFLAGS)

CursesWindow.o: CursesWindow.cpp CursesWindow.h
	g++ -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f *.o $(EXEC)
