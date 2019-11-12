#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int calcLIS(vector<int> line, int N) {
	int ret = 1, max = 0;
	int* dp = new int[N];
	memset(dp, -1, sizeof(int) * N);

	for (int i = N - 2; i > -1; --i) {
		max = 0;
		for (int j = i + 1; j < N; ++j) {
			if (line[i] < line[j]) {
				if (dp[j] == -1)
					dp[j] = 1;
				if (max < dp[j])
					max = dp[j];
			}
		}
		dp[i] = max + 1;

		if (ret < dp[i])
			ret = dp[i];
	}
	delete[] dp;

	return ret;
}

int main() {
	vector<int> answers;
	vector<int> line;
	int C, N, input;
	
	cin >> C;
	for (int i = 0; i < C; ++i) {
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> input;
			line.push_back(input);
		}
		answers.push_back(calcLIS(line, N));
		line.clear();
	}

	for (vector<int>::const_iterator it = answers.begin(); it != answers.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}