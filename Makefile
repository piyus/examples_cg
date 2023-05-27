exe := $(patsubst %.c,%,$(wildcard *.c))

default : $(exe)

%: %.c
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
	-./sizeinv5 -1
	-./sizeinv1
	-./sizeinv3
	-./sizeinv5 -20
	./ret1 4
	./ret1 -5

bad: $(exe)
	-./call1 5
	-./call2 5
	-./call1 -6
	-./call2 -6
	-./store1 4
	-./store2 4
	-./store1 -7
	-./store2 -7
	-./sizeinv2
	-./sizeinv4
	-./sizeinv5 -21
	-./sizeinv5 0
	-./ret1 5
	-./ret1 -6
	
clean:
	rm -rf $(exe) a.out trace.txt
