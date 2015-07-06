all: ch1

byte.o: byte.c byte.h

base64.o: base64.c base64.h

ch1: ch1.o byte.o base64.o

clean:
	rm *.o ch1
