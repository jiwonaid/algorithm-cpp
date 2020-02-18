#pragma warning(disable : 4996)

#include <iostream>
#include <limits>

using namespace std;

int dp[1000001];

void solve(int n, int count) {
	if (n < 1)
		return;
	if (dp[n] > count) {
		dp[n] = count;
		if (n % 3 == 0)
			solve(n / 3, count + 1);
		if (n % 2 == 0)
			solve(n / 2, count + 1);
		solve(n - 1, count + 1);
	}
}

int main() {
	int N, MAX = numeric_limits<int>::max();

	fill(dp, dp + 1000001, MAX);
	cin >> N;
	solve(N, 0);
	cout << dp[1] << '\n';

	return 0;
}