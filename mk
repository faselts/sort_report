objs= random_generation.o sort.o
flags+=-c -Wall -g

all:main.o random_generation.o sort.o sortw.o
	gcc main.o random_generation.o sort.o sortw.o -o all

main.o:main.c
	gcc main.c -c -o main.o

random_generation.o:random_generation.c
	gcc random_generation.c -c -o random_generation.o

sort.o:sort.c
	gcc sort.c -c -o sort.o

sortw.o:sortw.c
	gcc sortw.c -c -o sortw.o

clean:
	rm *.o all -f
