CFLAGS := -std=c99 -Wall -Werror -pedantic


CSOURCES := list.o file_funcs.o


TEST_SOURCES := list.o


%.o: %.c
	
	gcc -c $(CFLAGS) $<


test:  $(TEST_SOURCES)
	
	gcc $(CFLAGS) $^ test.c -o $@.exe

app: $(CSOURCES)
	
	gcc $(CFLAGS) $^ main.c -o $@.exe

clean:
	rm *.o *.exe
