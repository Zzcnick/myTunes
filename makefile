GCC = gcc -g

all: linked.o playlist.o main.o
	$(GCC) linked.o playlist.o main.o -o myTunes.out

linked.o: linked.c
	$(GCC) -c linked.c 

main.o: main.c
	$(GCC) -c main.c

playlist.o: playlist.c
	$(GCC) -c playlist.c

run: myTunes.out
	./myTunes.out

clean:
	make -i cleanH

cleanH:
	rm *~
	rm *.o
