%.o : %.c *.h
	gcc -c $< -std=c99 -Wall -Werror -ggdb 

app.exe: main.o pop.o print.o push.o start.o struct.o 
	gcc -o app.exe main.o pop.o print.o push.o start.o struct.o 

clean:
	rm *.o *.exe