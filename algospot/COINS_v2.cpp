#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int calCoins(int M, int C, int coins[]) {
	int* dp = new int[M + 1];
	memset(dp, 0, sizeof(int) * (M + 1));

	dp[0] = 1;

	for (int i = 0; i < C; i++) {
		for (int j = coins[i]; j <= M; j++) {
			dp[j] += dp[j - coins[i]];
			if (dp[j] > 1000000007)
				dp[j] = dp[j] % 1000000007;
		}
	}
	
	return dp[M];
}

int main() {
	vector<int> answers;
	int T;
	int M, C;

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> M >> C;
		int* coins = new int[C];
		for (int j = 0; j < C; ++j) {
			cin >> coins[j];
		}

		int result = calCoins(M, C, coins);
		delete[] coins;
		answers.push_back(result);
	}

	for (vector<int>::const_iterator it = answers.begin(); it != answers.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}