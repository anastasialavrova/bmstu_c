GCC := gcc
FLAGS := -std=c99 -Wall -Werror -D EXPORTS -c -ggdb
OBJF := check.o key.dll mysort.dll error_decoder.o read.o write.o
LIBF := -lmysort -lkey


%.o : %.c *.h
	$(GCC) $(FLAGS) -c $<

%.dll : %_lib.o
	$(GCC) -shared $^ -Wl,--subsystem,windows -o $@

app.exe : $(OBJF) main.o
	$(GCC) $^ -L. $(LIBF) -o $@

tests.exe : $(OBJF) test.o
	$(GCC) $^ -L. $(LIBF) -o $@

clean :
	rm *.o *.exe *.dll