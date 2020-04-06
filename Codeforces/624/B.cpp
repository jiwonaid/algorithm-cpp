#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> a, operations, p;

void bubble() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				operations[j]++;
			}
		}
	}
}

void solve() {
	for (int i = 0; i < n; ++i) {
		if (operations[i] != 0)
			if (find(p.begin(), p.end(), i + 1) == p.end()) {
				printf("NO\n");
				return;
			}
	}
	printf("YES\n");
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		a.resize(n);
		operations.assign(n, 0);
		p.resize(m);
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		for (int i = 0; i < m; ++i)
			scanf("%d", &p[i]);
		bubble();
		solve();
	}

	return 0;
}