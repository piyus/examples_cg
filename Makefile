exe := $(filter-out lib, $(patsubst %.c,%,$(wildcard *.c)))
export LD_LIBRARY_PATH=../jemalloc/lib

default : $(exe)

lib.o: lib.c
	../build/bin/clang -g -fsanitize=fastaddress -O3 -c -o $@ $^

%: %.c lib.o
	../build/bin/clang -g -fsanitize=fastaddress -O3 -o $@ $^ -L ../jemalloc/lib -ljemalloc_cg -lsupport

good: $(exe)
	./call1 4
	./call2 4
	./call1 -5
	./call2 -5
	./store1 3
	./store2 3
	./store1 -6
	./store2 -6
	-./sizeinv1
	-./sizeinv2
	-./sizeinv3 -1
	-./sizeinv3 -20
	-./sizeinv4 -1
	-./sizeinv4 -20
	-./sizeinv5 -1
	-./sizeinv5 -20
	-./sizeinv7
	-./sizeinv8 -1
	-./sizeinv8 -20
	./ret1 4
	./ret1 -5
	./loop1 10000 10000
	./loop2 10000 10000
	./loop1 10000 0
	./loop2 10000 0
	./loop1 10000 1
	./loop2 10000 1

bad: $(exe)
	-./call1 5
	-./call2 5
	-./call1 -6
	-./call2 -6
	-./store1 4
	-./store2 4
	-./store1 -7
	-./store2 -7
	-./sizeinv3 -0
	-./sizeinv3 -21
	-./sizeinv4 0
	-./sizeinv4 -21
	-./sizeinv5 0
	-./sizeinv5 -21
	-./sizeinv8 0
	-./sizeinv8 -21
	-./ret1 5
	-./ret1 -6
	-./loop1 10000 10001
	-./loop2 10000 10001

clean:
	rm -rf $(exe) a.out trace.txt lib.o
