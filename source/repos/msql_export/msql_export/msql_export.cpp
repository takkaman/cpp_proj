// msql_export.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "export.h"
#include <string>
using namespace std;
//#pragma comment(lib,"libmysql.lib")

int main()
{
	string database = "dexin";
	string table = "customer";
	exportMySQLTable(database, table);
	system("pause");

	return 0;

}

