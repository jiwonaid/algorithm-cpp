#include<iostream>

using namespace std;

const int MOD = 10 * 1000 * 1000;
int cache[101][101];

int poly(int n, int first) {
	if (n == first)
		return 1;

	int& ret = cache[n][first];
	if (ret != -1)
		return ret;

	ret = 0;
	for (int second = 1; second <= n - first; ++second) {
		int add = first + second - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}

int main() {
	int C, n;

	cin >> C;
	fill(&cache[0][0], &cache[0][0] + 101 * 101, -1);
	for (int i = 0; i < C; ++i) {
		cin >> n;
		int sum = 0;
		for (int j = 1; j <= n; ++j) {
			sum += poly(n, j);
			sum %= MOD;
		}
		cout << sum << endl;
	}

	return 0;
}