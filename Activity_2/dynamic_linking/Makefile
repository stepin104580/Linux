TARGET=sall.out
OBJS=test.o src/mystring.o  src/bit.o src/number.o

TOPDIR=${PWD}
CFLAGS=-I${TOPDIR}/include
LDFLAGS=-lmystring -lnumber -lbit
LIBPATH=${PWD}

all:sall.out

sall.out:test.o libmystring.a libnumber.a libbit.a
	gcc -L${LIBPATH} $< -o $@ ${LDFLAGS} 
libmystring.a:src/mystring.o 
	ar rc $@ $^
libnumber.a:src/number.o 
	ar rc $@ $^
libbit.a:src/bit.o 
	ar rc $@ $^
%.o:src/%.c include/%.h

test.o: test.c include/*.h

test:
	./sall.out

clean:
	rm -rf *.a *.o src/*.o ${TARGET}
