#makefile

Evolution: Ev1.o RandInput.o consdef.o outgen.o
	gcc Ev1.o RandInput.o consdef.o outgen.o -o Evolution
Ev1.o: Ev1.c Consts1.h RandInput.c consdef.c outgen.c
	gcc -c -Wall -pedantic Ev1.c RandInput.c consdef.c outgen.c
RandInput.o: RandInput.c Consts1.h
	gcc -c -Wall -pedantic RandInput.c
consdef.o: consdef.c
	gcc -c -Wall -pedantic consdef.c
outgen.o: outgen.c consdef.o RandInput.c Consts1.h
	gcc -c -Wall -pedantic outgen.c RandInput.c
clean:
	rm -f *.o *.csv.* Evolution
