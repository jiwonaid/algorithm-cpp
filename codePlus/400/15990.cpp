#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

long long dp[100001][4];

void calc(int n) {
	dp[1][1] = 1;
	dp[1][0] = 1;
	dp[2][2] = 1;
	dp[2][0] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	dp[3][0] = 3;

	for (int i = 4; i <= n; ++i) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % 1000000009;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % 1000000009;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % 1000000009;
		dp[i][0] = (dp[i][1] + dp[i][2] + dp[i][3]) % 1000000009;
	}
}

int main() {
	int T, n;

	fill(&dp[0][0], &dp[0][0] + 100001 * 4, 0);
	calc(100000);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("%d\n", dp[n][0]);
	}

	return 0;
}