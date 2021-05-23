all: main.c bst.o ll.o arr.o bs.o hash.o rand.o
	gcc main.c bst.o ll.o arr.o bs.o hash.o rand.o -o main.out
bst.o: bst.c data.h
	gcc -c bst.c -o bst.o
ll.o: ll.c data.h
	gcc -c ll.c -o ll.o
arr.o: arr.c data.h
	gcc -c arr.c -o arr.o
bs.o: bs.c data.h
	gcc -c bs.c -o bs.o
hash.o: hash.c data.h
	gcc -c hash.c -o hash.o
rand.o: rand.c data.h
	gcc -c rand.c -o rand.o
clean:
	rm -f bst.o ll.o arr.o bs.o hash.o rand.o main.out