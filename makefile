all: main.c bst.o ll.o arr.o bs.o hash.o rand.o
	gcc main.c bst.o ll.o arr.o bs.o hash.o rand.o
bst.o: bst.c 
	gcc -c bst.c -o bst.o
ll.o: ll.c
	gcc -c ll.c -o ll.o
arr.o: arr.c 
	gcc -c arr.c -o arr.o
bs.o: bs.c 
	gcc -c bs.c -o bs.o
hash.o: hash.c 
	gcc -c hash.c -o hash.o
rand.o: rand.c 
	gcc -c rand.c -o rand.o
clean:
	rm -f bst.o ll.o arr.o bs.o hash.o rand.o a.out