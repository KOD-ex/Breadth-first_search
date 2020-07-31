all: breadth_first_search

breadth_first_search: main.o breadth_first_search.o
	gcc main.o breadth_first_search.o -o my_binary

main.o: main.c
	gcc -c main.c

breadth_first_search.o: breadth_first_search.c
	gcc -c breadth_first_search.c

clean:
	rm -rf *.o breadth_first_search