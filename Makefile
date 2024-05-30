cc=gcc -std=c11
ar=ar rcs
flags=-Wall -Wextra -Werror -pedantic
hpath=/usr/local/include
libpath=/usr/local/lib

libdefer:
	$(cc) $(flags) -c -o defer.o defer.c
	$(ar) libdefer.a defer.o

install: libdefer
	sudo cp libdefer.a $(libpath)
	sudo cp defer.h $(hpath)

uninstall:
	sudo rm $(libpath)/libdefer.a
	sudo rm $(hpath)/defer.h
	