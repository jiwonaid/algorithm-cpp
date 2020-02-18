#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

int dp[1001];

int cover(int n) {
	int& ret = dp[n];

	if (n == 0)
		return 1;
	else if (ret != -1)
		return ret;
	else
		ret = (cover(n - 1) + cover(n - 2)) % 10007;
	
	return ret;
}

int main() {
	int n;

	fill(dp, dp + 1001, -1);
	cin >> n;
	cout << cover(n) << '\n';
	
	return 0;
}