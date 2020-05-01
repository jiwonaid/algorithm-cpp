#pragma warning(disable : 4996)

#include <iostream>
#include <vector>

using namespace std;

int n, m, cnt = 0;
vector<int> cache;

void solve() {
	for (int i = 1; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			cache[j] -= cache[i - 1];
			if (cache[j] == m)
				cnt++;
		}
	}
}

int main () {
	scanf("%d %d", &n, &m);
	cache.resize(n);
	int input, temp = 0;
	for (int i = 0; i < n; ++i) {
		scanf(" %d", &input);
		temp += input;
		cache[i] = temp;
		if (cache[i] == m)
			cnt++;
	}

	solve();
	printf("%d", cnt);

	return 0;
}