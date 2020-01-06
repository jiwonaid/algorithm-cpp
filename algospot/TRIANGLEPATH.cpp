#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> triangle;
vector<vector<int>> dp;

void calPath(int i, int j) {
	if(dp[i + 1][j] < dp[i][j] + triangle[i + 1][j])
		dp[i + 1][j] = dp[i][j] + triangle[i + 1][j];
	if (dp[i + 1][j + 1] < dp[i][j] + triangle[i + 1][j + 1])
		dp[i + 1][j + 1] = dp[i][j] + triangle[i + 1][j + 1];
}

int calMax(const vector<vector<int>>& triangle) {
	int ret = 0;

	dp[0][0] = triangle[0][0];
	for (int i = 0; i < triangle.size() - 1; ++i) {
		for (int j = 0; j <= i; ++j) {
			calPath(i, j);
			if (ret < dp[i][j])
				ret = dp[i][j];
		}
	}

	return ret;
}

int main() {
	int C, n, input;
	vector<int> answers;

	cin >> C;
	if (C < 1)
		exit(-1);

	for (int i = 0; i < C; ++i) {
		cin >> n;
		triangle.assign(n + 1, vector<int>(n + 1, 0));
		dp.assign(n + 1, vector<int>(n + 1, 0));
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k <= j; ++k) {
				cin >> input;
				triangle[j][k] = input;
			}
		}
		answers.push_back(calMax(triangle));
	}

	for (int i : answers) {
		cout << i << endl;
	}

	return 0;
}