#include <stdlib.h>
#include <stdio.h>

#include "mysql.h"

MYSQL my_connection;
MYSQL_RES *res_ptr;
MYSQL_ROW sqlrow;


void display_header();
void display_row();

int main(int argc, char *argv[]) {
	int res;
	char *str_na = "name";
	char *str_nu = "num";
	char *str_ag = "age";
	int first_row = 1; /* used ensure we display the row header */
	int n = 0;
	mysql_init(&my_connection);
	if(mysql_real_connect(&my_connection, "localhost", "root", "root", "linuxc", 0, NULL, 0)) {
		fprintf(stdout,"mysql connect success\n");
		res = mysql_query(&my_connection, "drop table if  exists children");
		res = mysql_query(&my_connection, "create table children (num int, age int, name varchar(6), primary key (num))");
		res = mysql_query(&my_connection, "insert into  children (num, age, name) values(1, 18, 'liu'),(2, 28,'yang')");
		if(!res) { 	
			printf("CREATE TABLE SUCCESS");
			res = mysql_query(&my_connection, "select * from children");
			if(!res) {
				printf("show tables success;\n");
				res_ptr = mysql_use_result(&my_connection);
				if(res_ptr) {
					printf("we have got %lu rows\n",(unsigned long)mysql_num_rows(res_ptr));
					printf("%6s|%6s|%6s\n", str_nu, str_ag, str_na);
					while((sqlrow = mysql_fetch_row(res_ptr))) {
						display_row();
						n++;
						if (n%3) {
						printf("|\n");
						}
					}	
				}
			} else {
				fprintf(stderr, "we have a trouble:%s\n", mysql_error(&my_connection));
			  }
		} else {	
			fprintf(stderr,"we have make a err%s:\n",mysql_error(&my_connection));
		  }
	} else {
		fprintf(stderr,"connect mysql failed cause: %s\n", mysql_error(&my_connection));
	  }
	
	return EXIT_SUCCESS;

}






void display_row() {
	unsigned int field_count;

	field_count = 0;
	while (field_count < mysql_field_count(&my_connection))	{
		printf("|%6s", sqlrow[field_count]);
		field_count++;
	}
}
