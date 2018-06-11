// msql_export.cpp : Defines the entry point for the console application.
//

#include <windows.h>
#include "stdafx.h"
#include <mysql.h>
#include <string>
#include <iostream>

using namespace std;

#pragma comment(lib,"libmysql.lib")


int main()
{
	const char user[] = "root";
	const char pswd[] = "123456";
	const char host[] = "47.101.57.53";
	const char table[] = "hat";
	unsigned int port = 3306;
	MYSQL myCont;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	int res;
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0))
		//if (mysql_real_connect(&myCont, host, user, pswd,0,0,NULL,0))
	{
		mysql_query(&myCont, "SET NAMES UTF8"); //set encode
											//  mysql_select_db(&myCont, table);
		res = mysql_query(&myCont, "select * from result");//query
		if (!res)
		{
			result = mysql_store_result(&myCont);
			cout << "query count:" << mysql_num_rows(result) + 1 << endl;
			if (result)
			{
				while (sql_row = mysql_fetch_row(result))// get row info
				{
					cout << "ID:" << sql_row[1] << endl;
					cout << "Name:" << sql_row[2] << endl;
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
	system("pause");

	return 0;

}

