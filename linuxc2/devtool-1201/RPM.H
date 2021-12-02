//diff  -c file1 file2 >diffs
//patch file1 diffs
//RPM包格式 name-version-release.architectur.rpm
//打包---创建spec文件----rpmbuild建立rpm包

#管理函数库的语法 lib（file.o）含义是file.o 是存储在lib.a中的
#默认规则是 .c.a:
				$(CC) -c $(CFLAGS) $<
				$(AR) $(ARFLAGS) $@ $*.o

#将a.o b.o放入函数库mylib.a中
all: myapp 
#宏定义
CC = gcc
INCLUDE = .
CFLAGS = -g -Wall -ansi
INSTDIR = /usr/bin
MYLIB = mylib.a

#规则头用tab开始
myapp: main.o $(MYLIB)
	$(CC) -o myapp main.o $(MYLIB)
$(MYLIB): $(MYLIB)(a.o)  $(MYLIB)(b.o)
main.o: main.c
a.o: a.c
b.o: b.c

clean:
	-rm -rf a.o b.o main.o $(MYLIB)

dist: myapp-1.0.tar.gz


myapp-1.0.tar.gz: myapp myapp1
    -rm -rf myapp1.0
    mkdir myapp-1.0
    cp *.c *.h *.l Makefile myapp-1.0
    tar -zcvf $@ myapp-1.0