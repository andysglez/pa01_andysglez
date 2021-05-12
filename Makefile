CXXFLAGS: -std=c++11
game: cards.o main.o
	g++ $(CXXFLAGS) cards.o main.o -o game;
test: testcards.o cards.o
	g++ $(CXXFLAGS) testcards.o cards.o -o test;
testcards.o: testcards.cpp testcards.h
	g++ -c testcards.cpp
cards.o: cards.cpp cards.h
	g++ -c cards.cpp
main.o: main.cpp cards.h
	g++ -c main.cpp
clean:
	rm *.o game test