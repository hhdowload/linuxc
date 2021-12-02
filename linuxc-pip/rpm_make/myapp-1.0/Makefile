
##makefiel：
#	自动处理依赖问题
#	减少编译时间  
#	生成lib.a/.so静态动态库文件  


#which compiler
CC = gcc
INCLUDE = .
INSTALL = /usr/bin
#options for develop 
CFLAGS = -g -Wall -ansi #生成gdb调试信息 打开告警 
MYLIB = mylib.a

#默认make只执行生成第一个目标文件
all: myapp

myapp: main.o ${MYLIB}
#默认规则	${CC} -o myapp 2.o 3.o main.o
	${CC} ${CFLAGS} -o myapp main.o ${MYLIB}


##默认规则生成.a函数库存放.o文件
##.c.a:
##	${CC} -c ${CFLAGS} $< 
##	${AR} ${ARFLAGS} $@  $*.o
################################

${MYLIB}: ${MYLIB}(2.o)  ${MYLIB}(3.o)



##gcc -MM 自动梳理源文件的依赖关系 EX: gcc  - MM a.c b.c main.c
main.o: main.c a.h
#	${CC} -I${INCLUDE} -c main.c  
2.o: 2.c a.h b.h
#	${CC} -I${INCLUDE} -c 2.c
3.o: 3.c b.h c.h
#	${CC} -I${INCLUDE} -c 3.c


clean:
#	-rm main.o 2.o 3.o
	-rm main.o 2.o 3.o ${MYLIB}
	-rm myapp ${INSTALL}/myapp

install: myapp
	@if [ -d ${INSTALL} ]; then \
		cp myapp ${INSTALL}/myapp; \
		chmod 755 ${INSTALL}/myapp; \
		echo "we have installed mypp application"; \
	else \
		echo "sorry,${INSTALL} not exist"; \
	fi




dist: myapp-1.0.tar.gz

myapp-1.0.tar.gz: myapp myapp.1
	-rm -rf myapp-1.0
	mkdir myapp-1.0
	cp *.c *.h *.1 Makefile myapp-1.0
	tar zcvf $@ myapp-1.0