CC = gcc
AR = ar
FLAGS = -Wall -g

all: frequency

frequency: trie.o main.o
	$(CC) $(FLAGS) -o $@ $^

main.o: main.c trie.h
	$(CC) $(FLAGS) -c $<

trie.o: trie.c trie.h
	$(CC) $(FLAGS) -fPIC -c $<

.PHONY: clean all

clean:
	rm -f *.o frequency
