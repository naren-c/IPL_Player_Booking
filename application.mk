ipl : IPLclient.o file_operations.o admin.o teams.o 
	gcc -o ipl IPLclient.o file_operations.o admin.o teams.o
IPLclient.o : IPLclient.c admin.h teams.h file_operations.h
	gcc -c IPLclient.c
file_operations.o : file_operations.c file_operations.h
	gcc -c file_operations.c
admin.o : admin.c admin.h
	gcc -c admin.c
teams.o : teams.c teams.h
	gcc -c teams.c