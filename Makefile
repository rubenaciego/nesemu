
NAME = emulator
CC = gcc
CFLAGS = -I. -g

all:
	${CC} ${CFLAGS} *.c -o build/${NAME}
	
clean:
	rm build/${NAME}
