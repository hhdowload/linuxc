#gcc -Wall -ansi -g
#gcc -DDEBUG    

//打开取样法，不加选项关闭调试信息
#ifdef DDEBUG
    printf("print some thing\n");
#endif

//调试宏 
#gcc -DDEBUG=5 启用basic_debug和super_debug ; -DDEBUG=0将禁用调试信息
#define BASIC_DEBUG 1
#define EXTRA_DEBUG 2
#define SUPER_DEBUG 4

#if (DEBUG & EXTRA_DEBUG)
    printf ....
#endif

//在程序中添加如下信息，在不适用调试信息时候不必要在命令行定义宏
#ifdef DEBUG
#define DEBUG  0
#endif

/*c语言预处理器定义的宏
 _LINE_       当前行号的十进制数
 _FILE_       当前文件名的字符串
 _DATE_       mmm ddd yyy 格式的当前日期
 _TIME_       hh:mm:ss 当前时间
int main() {
    #ifdef DEBUG
    printf("compiled: "_DATE_\n");
    #endif
}
*/

//无需重新编译的调试技巧
if(debug) {
    sprintf(msg, ...);
    write_debug(msg);
}




