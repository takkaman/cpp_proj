// pat_a_1071.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

struct Word {
	string word;
	int cnt;
};

map<string, int> wordMap;
vector<Word> result;
vector<string> output;

bool cmp(Word a, Word b) {
	return a.cnt > b.cnt;
}

int main()
{
	int i = 0, j, start = 0, end, prev;
	string input, word;
	getline(cin, input);
	//while (input[i] != '"') {
	//	i++;
	//}
	//start = i + 1;
	end = input.length();
	j = start;
	while (start < end) {
		while (((input[j] >= '0' && input[j] <= '9') || (input[j] >= 'a' && input[j] <= 'z') || (input[j] >= 'A' && input[j] <= 'Z')) && j < end) {
			j++;
		}
		word = input.substr(start, j - start);
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		if (wordMap.find(word) != wordMap.end()) {
			wordMap[word] += 1;
		}
		else {
			wordMap[word] = 1;
		}
		//cout << word << endl;
		while (!((input[j] >= '0' && input[j] <= '9') || (input[j] >= 'a' && input[j] <= 'z') || (input[j] >= 'A' && input[j] <= 'Z')) && j < end) {
			j++;
		}
		start = j;
	}
	
	for (auto &m : wordMap) {
		Word w = { m.first, m.second };
		result.push_back(w);
	}

	sort(result.begin(), result.end(), cmp);
	prev = result[0].cnt;

	for (auto &v : result) {
		if (v.cnt == prev) {
			output.push_back(v.word);
		}
		else {
			break;
		}
	}

	sort(output.begin(), output.end());

	cout << output[0] << " " << wordMap[output[0]];

	system("pause");
    return 0;
}

