#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;
int cache[101];

int tiling(int n) {
	if (n <= 1)
		return 1;

	int& ret = cache[n];
	if (ret != -1)
		return ret;
	
	ret = (tiling(n - 1) + tiling(n - 2)) % MOD;
	return ret;
}

int main() {
	int C, n;

	cin >> C;
	for (int i = 0; i < C; ++i) {
		cin >> n;
		fill(cache, cache + 101, -1);
		cout << tiling(n) << endl;
	}

	return 0;
}