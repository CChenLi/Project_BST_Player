
game: main.cpp cards.cpp utility.cpp
	g++ main.cpp cards.cpp utility.cpp -o game

test: tests.cpp cards.cpp utility.cpp
	g++ tests.cpp utility.cpp cards.cpp -o test

try: try.cpp cards.cpp utility.cpp
	g++ try.cpp utility.cpp cards.cpp -o try

