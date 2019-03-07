st: main.c BST.c BST.h
	make -f makefile.static

dm: main.c BST.c BST.h
	make -f makefile.dynamic

.PHONY: clean

clean:
	rm -f *.o *.out *.a *.so
