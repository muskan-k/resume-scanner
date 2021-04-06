scan: Cproj.o func.o
	gcc Cproj.o func.o -o scan
Cproj.o: Cproj.c server.h
	gcc -c Cproj.c 
func.o: func.c 
	gcc -c func.c 