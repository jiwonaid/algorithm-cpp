#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int getUpperD(vector<vector<int>> dpD, int i, int j) {
	int t1, t2;
	
	if (j == 0) {
		t1 = -1;
		t2 = dpD[i - 1][j];
	}
	else if (i - 1 < j) {
		t1 = dpD[i - 1][j - 1];
		t2 = -1;
	}
	else {
		t1 = dpD[i - 1][j - 1];
		t2 = dpD[i - 1][j];
	}
	
	return max(t1, t2);
}

int calcDPath(vector<vector<int>> dpD, int N) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			if (i == 0 && j == 0)
				continue;
			else
				dpD[i][j] += getUpperD(dpD, i, j);
		}
	}
	for (int i = N; i < 2 * N - 1; ++i) {
		for (int j = 0; j < 2 * N - 1 - i; ++j) {
			dpD[i][j] += max(dpD[i - 1][j], dpD[i - 1][j + 1]);
		}
	}

	return dpD[2 * N - 2][0];
}

int main() {
	vector<int> answers;
	vector<vector<int>> diamond;
	vector<int> line;
	int C, N, input;
	
	cin >> C;
	for (int i = 0; i < C; ++i) {
		cin >> N;
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < j + 1; ++k) {
				cin >> input;
				line.push_back(input);
			}
			diamond.push_back(line);
			line.clear();
		}
		for (int j = N; j < 2 * N - 1; ++j) {
			for (int k = 0; k < 2 * N - 1 - j; ++k) {
				cin >> input;
				line.push_back(input);
			}
			diamond.push_back(line);
			line.clear();
		}
		answers.push_back(calcDPath(diamond, N));
		diamond.clear();
	}

	for (vector<int>::const_iterator it = answers.begin(); it != answers.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}