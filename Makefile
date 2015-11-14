project: evalexp.o integer.o quadratic.o lineareq.o main.o
	cc evalexp.o integer.o quadratic.o lineareq.o main.o -lm -o project
	clear

evalexp.o: evalexp.c main.c cal.h
	cc -c evalexp.c
	cc -c main.c
	
integer.o: integer.c main.c cal.h
	cc -c integer.c
	cc -c main.c
	
quadratic.o: quadratic.c main.c cal.h
	cc -c quadratic.c
	cc -c main.c
	
lineareq.o: lineareq.c main.c cal.h
	cc -c lineareq.c
	cc -c main.c
	
main.o: main.c cal.h
	cc -c main.c
	
