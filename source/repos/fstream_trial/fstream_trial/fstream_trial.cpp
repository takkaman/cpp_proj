// fstream_trial.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ifstream inf;
	ofstream outf;
	string l, s1, s2, s3, s4;

	inf.open("D://work//projects//cpp_proj//source//repos//fstream_trial//content.txt");
	outf.open("out.txt");

	while (getline(inf, l)) {
		istringstream sin(l);
		sin >> s1 >> s2 >> s3 >> s4;
		cout << s4 << " " << endl;
		outf << l << endl;
		//cout << l << endl;
	}

	inf.close();
	outf.close();

	system("pause");
    return 0;
}

