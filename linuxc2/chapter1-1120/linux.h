/*************************README******************************************
头文件
    #常量的定义
    #系统函数库函数调用声明
    #gcc -I/usr/openwin/include fred.c 可以使用-I选项指定非标准目录头文件
库文件
    #编译好的函数集合
    #库文件名以lib开头
    #.a/静态库， .so/共享库
    #.a/静态库， .so/共享库
    #-L/LUJING/  指定库路径
        #创建库文件 ar crv libfoo.a argc.o argv.o
        #gcc -o main_a main.o -L. -larg
        #gcc -o main_a main.o -L. libarg.a
    #.so/共享库
        
*************************README*******************************************/
