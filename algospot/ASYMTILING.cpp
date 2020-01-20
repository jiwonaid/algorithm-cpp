#include <iostream>

using namespace std;

const int MOD = 1000000007;
int t[101];

int tiling(int n) {
	if (n <= 1)
		return 1;

	int& ret = t[n];
	if (ret != -1)
		return ret;

	ret = (tiling(n - 1) + tiling(n - 2)) % MOD;
	return ret;
}

int asymTiling(int n) {
	if (n % 2 == 1) {
		return (tiling(n) - tiling((n - 1) / 2) + MOD) % MOD;
	}
	int ret = (tiling(n) - tiling((n - 2) / 2) + MOD) % MOD;
	ret = (ret - tiling(n / 2) + MOD) % MOD;
	return ret;
}

int main() {
	int C, n;

	cin >> C;
	fill(t, t + 101, -1);
	for (int i = 0; i < C; ++i) {
		cin >> n;
		cout << asymTiling(n) << endl;
	}

	return 0;
}