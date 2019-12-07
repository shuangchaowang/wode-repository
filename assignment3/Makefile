a3: main.o lts.o lps.o lcs.o lcps.o
	gcc -Wall -std=c99 main.o lts.o lps.o lcs.o lcps.o -o a3.exe
main.o: main.c lts.h lps.h lcs.h lcps.h
	gcc -Wall -std=c99 -c main.c
lts.o: lts.c lts.h
	gcc -Wall -std=c99 -c lts.c
lps.o: lps.c lps.h
	gcc -Wall -std=c99 -c lps.c
lcs.o: lcs.c lcs.h
	gcc -Wall -std=c99 -c lcs.c
lcps.o: lcps.c lcps.h
	gcc -Wall -std=c99 -c lcps.c