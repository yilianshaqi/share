a.out:main.o addbook.o findbook.o deletebook.o 
	gcc $^ -o a.out 
main.o:
	make -C main
addbook.o:addbook.c
	gcc -c addbook.c -o addbook.o -I ./include
findbook.o:findbook.c
	gcc -c findbook.c -o findbook.o -I ./include
deletebook.o:deletebook.c
	gcc -c deletebook.c -o deletebook.o -I ./include





.PHONY:delete
delete:
	rm *.o

