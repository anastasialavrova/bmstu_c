%.o : %.c *.h
	gcc -c $< -std=c99 -Wall -Werror -ggdb 

app.exe: main.o my_func.o test.o 
	gcc -o app.exe main.o my_func.o test.o 

clean:
	rm *.o *.exe