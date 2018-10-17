mainmake: main.c
	@gcc -g -o main main.c -lprofiler -ltcmalloc
	@./main