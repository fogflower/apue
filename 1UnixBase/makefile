CC=gcc 
DEPENS=../apue.h
LIBSS=../lib
CFLAGS=-I..
#这里定义了一个规则，依赖是.c和Depends使用gcc，其中-o $@是使得输出是:前半部分， $<表示后面的依赖的第一个元素, $^表示后半部分。
#%.o: %.c $(DEPENS)
#	$(CC) -c -o $@ $< $(CFLAGS)  

_OBJ=1_1_3list.o 
_OBJOUT=error.o

_OBJOUT1=$(patsubst %,$(LIBSS)/%,$(_OBJOUT))


1_1_3list: $(_OBJ) $(_OBJOUT1)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f $(_OBJ) 
