all: ch1 ch2

byte.o: byte.c byte.h

base64.o: base64.c base64.h

ch1: ch1.o byte.o base64.o

ch2: ch2.o byte.o

clean:
	rm *.o ch1 ch2
