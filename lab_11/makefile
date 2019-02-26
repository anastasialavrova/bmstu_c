%.o : %.c *.h
	gcc -c $< -std=c99 -Wall -Werror -ggdb 

app.exe: main.o test.o my_snprintf.o func.o
	gcc -o app.exe main.o test.o my_snprintf.o func.o

clean:
	rm *.o *.exe