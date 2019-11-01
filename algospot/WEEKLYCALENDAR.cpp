#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<string, int> days = { {"Sunday", 0}, {"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}, {"Saturday", 6} };

int getNumOfDays(int month) {
	switch (month) {
	case 0:
		// December
		return 31;
		break;
	case 1:
		return 31;
		break;
	case 2:
		return 28;
		break;
	case 3:
		return 31;
		break;
	case 4:
		return 30;
		break;
	case 5:
		return 31;
		break;
	case 6:
		return 30;
		break;
	case 7:
		return 31;
		break;
	case 8:
		return 31;
		break;
	case 9:
		return 30;
		break;
	case 10:
		return 31;
		break;
	case 11:
		return 30;
		break;
	case 12:
		//  December
		return 31;
		break;
	}
}

int main() {
	vector<string> answers;
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int m, d;
		string s;
		string result;

		cin >> m >> d >> s;
		int nOfDays = getNumOfDays(m);

		int start = d - days.at(s);

		for (int j = start; j < start + 7; ++j) {
			if (0 < j && j <= nOfDays) {
				result += to_string(j);
			}
			else if (j <= 0) {
				result += to_string(getNumOfDays(m-1) + j);
			}
			else {
				result += to_string(j - nOfDays);
			}

			if (j != start + 6)
				result += " ";
		}
		answers.push_back(result);
	}

	for (vector<string>::const_iterator iter = answers.begin(); iter < answers.end(); ++iter) {
		cout << *iter << endl;
	}


	return 0;
}