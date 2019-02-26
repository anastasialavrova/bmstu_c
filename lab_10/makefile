%.o : %.c *.h
	gcc -c $< -std=c99 -Wall -Werror -ggdb 

app.exe: main.o add_from_file.o check.o copy.o pop.o sort.o start.o 
	gcc -o app.exe main.o add_from_file.o check.o copy.o pop.o sort.o start.o 

test.exe: test.o add_from_file.o check.o copy.o pop.o sort.o start.o
	gcc -o test.exe test.o add_from_file.o check.o copy.o pop.o sort.o start.o 

clean:
	rm *.o *.exe