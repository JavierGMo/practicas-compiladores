sumanumeros.tab.c: sumanumeros.y
	bison -d sumanumeros.y
lex.yy.c: practica1.l practica1.tab.c
	flex practica1.l
practica1.tab.o: practica1.tab.c
	gcc practica1.tab.c -c
lex.yy.o: lex.yy.c
	gcc lex.yy.c -c

a.out:	practica1.tab.o lex.yy.o
	gcc practica1.tab.o lex.yy.o -ll
run: a.out
	./a.out
clean:
	rm -r a.out *.c *.o *.h