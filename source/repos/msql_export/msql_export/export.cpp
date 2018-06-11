#include "stdafx.h"
#include "export.h"
#include <windows.h>
#include <mysql.h>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

#pragma comment(lib,"libmysql.lib")

void exportMySQLTable(const char table[]) {
	const char user[] = "root";
	const char pswd[] = "1234";
	const char host[] = "localhost";
	//const char host[] = "47.101.57.53";
	// const char table[] = "dexin";
	unsigned int port = 3306;
	MYSQL myCont;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	int res, num;
	FILE * output = fopen("output.csv", "w+");
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0))
		//if (mysql_real_connect(&myCont, host, user, pswd,0,0,NULL,0))
	{
		mysql_query(&myCont, "SET NAMES UTF8"); //set encode
												//  mysql_select_db(&myCont, table);
		res = mysql_query(&myCont, "select * from customer");//query
		if (!res)
		{
			result = mysql_store_result(&myCont);
			cout << "query count:" << mysql_num_rows(result) + 1 << endl;
			if (result)
			{
				num = mysql_num_fields(result);
				// cout << num << endl;
				while (sql_row = mysql_fetch_row(result))// get row info
				{
					for (int j = 0; j < num; j++) {
						cout << sql_row[j] << ",";
						fprintf(output, "%s,", sql_row[j]);
					}
					cout << endl;
					fprintf(output, "\n");
				}
				//if (!mysql_query(&myCont, "insert into level_1(Name,Count) values('DongGuoZheng',2)")) {
				//	cout << "insert success" << endl;
				//}
				//else {
				//	cout << "shibai" << endl;
				//	cout << mysql_error(&myCont) << endl;
				//}
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
		mysql_free_result(result);

	mysql_close(&myCont);
	fclose(output);
}