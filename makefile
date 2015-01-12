CC=g++
CFLAGS=--std=c++11 -c -Wall -g
LFLAGS=-o bin/leftyloosey

all: bin obj bin/leftyloosey

bin:
	mkdir bin

obj:
	mkdir obj

bin/leftyloosey: obj/leftyloosey.o obj/node.o obj/bot.o
	$(CC) $(LFLAGS) obj/leftyloosey.o obj/node.o obj/bot.o

obj/leftyloosey.o: src/leftyloosey.cpp src/node.hpp src/bot.hpp
	$(CC) $(CFLAGS) -o obj/leftyloosey.o src/leftyloosey.cpp

obj/node.o: src/node.cpp src/node.hpp src/bot.hpp src/enemytypes.hpp
	$(CC) $(CFLAGS) -o obj/node.o src/node.cpp

obj/bot.o: src/bot.cpp src/bot.hpp src/weapontypes.hpp
	$(CC) $(CFLAGS) -o obj/bot.o src/bot.cpp

clean:
	rm -rf bin/leftyloosey obj/*
