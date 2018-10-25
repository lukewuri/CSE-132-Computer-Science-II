##
# Makefile for assignment 1
##

# This rule is a special rule. It tells `make` that the `all` and `clean`
# rules do not actually create files named `all` or `clean`.
.PHONY: all clean test

##
# TODO --- define CC and CFLAGS here
CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c99


##
# TODO --- create an `all` rule indicating we want to build `manip`
all: manip


##
# TODO --- create a `manip` rule indicating how to build `manip`
manip: manipFunctions.o

# Clean gets rid of all the build files we create.
# TODO --- remove the compiled `manip`
clean:
	rm -rf manip

# You can run `make test` to test against several numbers:
test: manip
	./manip 0 > output.txt
	./manip 4294967295 >> output.txt
	./manip 2863311530 >> output.txt
	./manip 4294967040 >> output.txt
	./manip 1 >> output.txt
	./manip 1 >> output.txt
	./manip 100 >> output.txt
	./manip 10000 >> output.txt
	./manip -c 255 >> output.txt
	./manip -i 255 >> output.txt
	./manip -l 255 >> output.txt
	./manip -s 32 -i 1 >> output.txt
	./manip -s 16 -i 1 >> output.txt
	./manip -s 64 -i 1 >> output.txt
	diff -w reference.txt output.txt
