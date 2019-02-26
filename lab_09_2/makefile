%.o : %.c *.h
	gcc -c $< -std=c99 -Wall -Werror -ggdb 

app.exe: main.o check.o read.o replace.o start.o 
	gcc -o app.exe main.o check.o read.o replace.o start.o 

clean:
	rm *.o *.exe