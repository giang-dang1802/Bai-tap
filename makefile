all: bstrutils.c main.c
	@echo "all"
	gcc -c bstrutils.c 
	ar rcs libstrutils.a bstrutils.o
	gcc main.c libstrutils.a -o main_static
	./main_static

	gcc -c -fPIC bstrutils.c
	gcc -shared -o libstrutils.so bstrutils.o
	gcc main.c libstrutils.a -o main_shared
	LD_LIBRARY_PATH=. ./main_shared

static: bstrutils.c main.c
	@echo "static"
	gcc -c bstrutils.c 
	ar rcs libstrutils.a bstrutils.o
	gcc main.c libstrutils.a -o main_static
	./main_static

shared:bstrutils.c main.c
	@echo "shared"
	gcc -c -fPIC bstrutils.c
	gcc -shared -o libstrutils.so bstrutils.o
	gcc main.c libstrutils.a -o main_shared
	LD_LIBRARY_PATH=. ./main_shared

clean:
	@echo "clear"
	rm -f bstrutils.o
	rm -f libstrutils.a
	rm -f libstrutils.so
	rm -f main_static
	rm -f main_shared
	rm -f main.o
