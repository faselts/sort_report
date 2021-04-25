objs= random_generation.o sort.o sortw.o main.o
flags+=-c -Wall -g

all:$(objs)
	gcc $^ -o $@

%.o:%.c
	gcc $^ $(flags) -o $@

clean:
	rm *.o all -f
