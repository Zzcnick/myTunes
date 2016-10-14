GCC = gcc -g 

all: linked.o
	$(GCC) linked.c -o myTunes.out

run: myTunes.out
	./myTunes.out

clean:
	rm *~
	rm *.o
