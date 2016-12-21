ret= main.o addbook.o deletebook.o 
ret+= findbook.o
a.out :$(ret)

	gcc $(ret) -o a.out
addbook.o:addbook.c
	gcc -c addbook.c -o addbook.o -I ./include
deletebook.o :deletebook.c
	gcc -c deletebook.c -o deletebook.o -I ./include
findbook.o :findbook.c 
	gcc -c findbook.c -o findbook.o -I./include
main.o :
	make -C make


./PHONY:clean
clean:
	rm -f *.o a.out
