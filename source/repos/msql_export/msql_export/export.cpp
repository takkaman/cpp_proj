#include "stdafx.h"
#include "export.h"
#include <windows.h>
#include <mysql.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#pragma comment(lib,"libmysql.lib")

void exportMySQLTable(string database, string table) {
	const char user[] = "root";
	const char pswd[] = "1234";
	const char host[] = "localhost";
	// const char host[] = "47.101.57.53";
	// const char database[] = "dexin";
	unsigned int port = 3306;

	string base_query = "select * from `";
	string sql_query = base_query + table + "`";
	string output_file = table + ".csv";
	MYSQL myCont;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	int res, num;
	FILE * output = fopen(output_file.c_str(), "w+");
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, host, user, pswd, database.c_str(), port, NULL, 0))
		//if (mysql_real_connect(&myCont, host, user, pswd,0,0,NULL,0))
	{
		mysql_query(&myCont, "SET NAMES UTF8"); //set encode
												//  mysql_select_db(&myCont, table);
		res = mysql_query(&myCont, sql_query.c_str());//query
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
		return;
	}
	if (result != NULL)
		mysql_free_result(result);

	mysql_close(&myCont);
	fclose(output);
	return;
}