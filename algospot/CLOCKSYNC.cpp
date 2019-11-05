#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<vector<int>> arr = { {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13} };

bool isTwelve(int clocks[]) {
	for (int i = 0; i < 16; ++i) {
		if (clocks[i] % 12 != 0)
			return false;
		else if (i == 15)
			return true;
	}
}

void pushSwitch(int clocks[], int n) {
	for (int i = 0; i < arr[n].size(); ++i)
		clocks[arr[n][i]] += 3;
}

int solve(int pClocks[], int n, int count, int ret) {
	if (isTwelve(pClocks)) {
		ret = min(ret, count);
	}
	else if (n == 10) {
		return ret;
	}
	else {
		int clocks[16];
		memcpy(clocks, pClocks, sizeof(int) * 16);
		for (int i = 0; i < 4; ++i) {
			int temp = solve(clocks, n + 1, count, ret);
			ret = min(ret, temp);

			pushSwitch(clocks, n);
			count += 1;
		}
	}

	return ret;
}

int main() {
	vector<int> answers;
	int C;
	int clocks[16];

	cin >> C;
	
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < 16; ++j) {
			cin >> clocks[j];
		}
		int result = solve(clocks, 0, 0, 31);
		answers.push_back((result == 31) ? -1 : result);
	}

	for (vector<int>::const_iterator i = answers.begin(); i < answers.end(); ++i) {
		cout << *i << endl;
	}

	return 0;
}