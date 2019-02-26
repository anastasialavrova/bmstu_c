%.o : %.c *.h
	gcc -c $< -std=c99 -Wall -Werror -ggdb 

app.exe: main.o check.o mysort.o filter.o read.o write.o error_decoder.o
	gcc -o app.exe main.o check.o mysort.o filter.o read.o write.o error_decoder.o

tests.exe: tests.o mysort.o filter.o 
	gcc -o tests.exe test.o mysort.o filter.o 

clean:
	rm *.o *.exe