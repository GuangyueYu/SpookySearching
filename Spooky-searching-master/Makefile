CFLAGS = -Wall -O -std=c99

all: searchtest.c multitest_proc.c multitest_thread.c
		gcc -o searchtest searchtest.c multitest_proc.c multitest_thread.c -lpthread -lm
process: searchtest.c multitest_proc.o
		gcc searchtest.c multitest_proc.o

thread: searchtest.c multitest_thread.o
		gcc searchtest.c multitest_thread.o

multitest_proc.o:multitest_proc.c
		gcc -c multitest_proc.c 

multitest_thread.o:multitest_thread.c
		gcc -c multitest_thread.c -lpthread

clean:
		rm a.out; rm cnm
