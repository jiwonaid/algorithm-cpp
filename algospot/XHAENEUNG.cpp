#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string evaluate(string e1, string e2, char oper, string submitted);

const map< string, int > numbers = {
	   {"zero", 0},
	   {"one", 1},
	   {"two", 2},
	   {"three", 3},
	   {"four", 4},
	   {"five", 5},
	   {"six", 6},
	   {"seven", 7},
	   {"eight", 8},
	   {"nine", 9},
	   {"ten", 10}
};

int main() {
	vector<string> answers;
	int T;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		string e1, e2, submitted;
		char oper;

		cin >> e1 >> oper >> e2;
		cin.ignore(16, '=');

		cin >> submitted;

		answers.push_back(evaluate(e1, e2, oper, submitted));
	}

	for (vector<string>::const_iterator iter = answers.begin(); iter < answers.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}

string evaluate(string e1, string e2, char oper, string submitted) {
	int x = numbers.at(e1);
	int y = numbers.at(e2);
	int result;
	string sResult;

	if (oper == '+')
		result = x + y;
	else if (oper == '-')
		result = x - y;
	else // (oper == '*')
		result = x * y;

	if (result < 0 || result > 10)
		return "No";

	for (map<string, int>::const_iterator iter = numbers.begin(); iter != numbers.end(); ++iter) {
		if ((*iter).second == result)
			sResult = (*iter).first;
	}
	
	sort(sResult.begin(), sResult.end());
	sort(submitted.begin(), submitted.end());
	if (sResult == submitted)
		return "Yes";
	else
		return "No";
}