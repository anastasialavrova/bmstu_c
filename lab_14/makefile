%.o : %.c
	gcc -c $< -std=c99 -Wall -Werror -ggdb

test_list.exe: test_list.o func_list.o
	gcc -o test_list.exe test_list.o func_list.o

test_arr.exe: test_arr.o func_arr.o
	gcc -o test_arr.exe test_arr.o func_arr.o

clean:
	rm *.o *.exe