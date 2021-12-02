#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <mysql.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    MYSQL *connect_ptr;
    connect_ptr = malloc(BUFFER_SIZE);
    MYSQL_RES *res_ptr;
    res_ptr = malloc(BUFFER_SIZE);
    MYSQL_ROW sql_row;
    int field_count;

    
    //数据库初始化
    if(argc < 4) {
        fprintf(stderr, "Input correct type: ip username passwd dbname\n");
        exit(1);
    }

    // printf("%s-%s-%s-%s\n", argv[1], argv[2], argv[3], argv[4]);
    mysql_init(connect_ptr);
    if(mysql_real_connect(connect_ptr, argv[1], argv[2], argv[3], argv[4], 0, NULL, 0)) {     
        printf("mysql connect success\n");
    } else printf("failed to connect\n");
    if(mysql_errno(connect_ptr)) {
        fprintf(stderr, "errno/str====>%d: %s\n", mysql_errno(connect_ptr), mysql_error(connect_ptr));
        exit(EXIT_FAILURE);    
    }

    char db_name[BUFFER_SIZE];
    //执行创建数据库命令
    while (1) {
        printf("Input dbname would create(one name per [END] end): \n");
        scanf("%s", db_name);
        if(!strcmp(db_name, "END")) {
            printf("create database finsh..\n");
            break;
        }
        int res = mysql_query(connect_ptr, "select * from mysql.user");
        if(res == 0) {
            printf("create database %s SUCCESS\n", db_name);
        } else {
            fprintf(stderr, "create failed: %d: %s\n", mysql_errno(connect_ptr), mysql_error(connect_ptr));
          }

    }
        
    res_ptr = mysql_use_result(connect_ptr);
    if(res_ptr) {
        printf("we got %lu datas\n", (unsigned long)mysql_num_rows(res_ptr));
        //fetch结果存在mysql_row结构中，每次fetch1行数据出来  
        //判断sql_row列数，然后打印 
        while((sql_row = mysql_fetch_row(res_ptr))) {               
            for(field_count = 0; field_count < mysql_field_count(connect_ptr); field_count++) {
                printf("%s |", sql_row[field_count]);  
            }   
            printf("\n");
        }
    }  else {
            fprintf(stderr, "get failed: %d: %s\n", mysql_errno(connect_ptr), mysql_error(connect_ptr));
    }

    
    printf("bye..\n");
    //释放资源gg
    mysql_close(connect_ptr);
    // free(connect_ptr);
    exit(EXIT_SUCCESS);
}




/*sql语句封装

#include <stdio.h>
void main()
{
   char name[] = "xiaotiange";
   char age[] = "20";
   char pre_sql[] = "insert into stu values('%s','%s')";
   char sql[200];
   sprintf(sql,pre_sql,name,age);
   printf("%s\n",sql);
}
*/