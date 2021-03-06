#include "stdafx.h"
#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
struct student {                 //存放学生的各种信息 
	string name;                //学生学号 
	int code, markz, markm, GPA;   //编程成绩code，期中成绩markz，期末成绩markm，总评GPA 
	student() {
		markz = -1; markm = -1; GPA = 0;   //初始化 
	}
};
bool cmp(student a, student b) {
	if (a.GPA != b.GPA) {
		return a.GPA >b.GPA;       //按照总评递减 
	}
	else {
		return a.name < b.name;
	}//总评相等按照学号字母序递增 
}
int main()
{
	int p, m, n, score; string name;
	vector<student> pass;     //存放所有合格的学生信息 
	map<string, student> stu;  //建立学生学号和学生信息之间映射， 
	cin >> p >> m >> n;
	for (int i = 0; i<p; i++) {
		cin >> name >> score;
		if (score >= 200 && score <= 900) {   //只录入满足编程条件的学生 
			stu[name].name = name;
			stu[name].code = score;
		}
	}
	for (int i = 0; i<m; i++) {    //录入期中成绩 
		cin >> name >> score;
		if (stu.count(name) && score >= 0 && score <= 100) {    //如果这个人有编程成绩，并且期中成绩在范围内 
			stu[name].markz = score;
		}
		else continue;
	}
	for (int i = 0; i<n; i++) {    //录入期末成绩 
		cin >> name >> score;
		if (stu.count(name)) {    //如果这人有录入编程成绩 
			stu[name].markm = score;
			if (stu[name].markm <stu[name].markz) {      //如果期期末成绩小于期中成绩 
				stu[name].GPA = (int)round((stu[name].markz *0.4 + stu[name].markm*0.6));
			}
			else stu[name].GPA = stu[name].markm;      //否则直接等于期末成绩 
			if (stu[name].GPA >= 60) {   //总评超过60分，加入到pass内 
				pass.push_back(stu[name]);
			}
		}
		else continue;
	}
	sort(pass.begin(), pass.end(), cmp);    //排序 
	for (int i = 0; i<pass.size(); i++) {      //按照格式输出 
		cout << pass[i].name << ' ' << pass[i].code << ' ' << pass[i].markz << ' ' << pass[i].markm << ' ' << pass[i].GPA << endl;
	}
	system("pause");
	return 0;
}
