WARNFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic

all: shortmain

shortmain: clean
	g++ $(WARNFLAGS) -g main.cpp -o assign_4.elf

main: clean dlist dnode
	g++ $(WARNFLAGS) -g main.cpp dlist.o dnode.o -o assign_4.elf

dlist: dnode
	g++ $(WARNFLAGS) -c -g dlist.cpp -o dlist.o

dnode:
	g++ $(WARNFLAGS) -c -g dnode.cpp -o dnode.o

syntax:
	g++ $(WARNFLAGS) -fsyntax-only $(FILE)

clean:
	rm -rf ./*.o ./*.elf
