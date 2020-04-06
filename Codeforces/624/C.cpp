#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
string s;
vector<int> p, pushed, result;

void solve() {

	for (int i = 0; i < p[0]; ++i) {
		pushed[i] = m + 1;
	}
	for (int i = 1; i < m; ++i) {
		for (int j = p[i - 1]; j < p[i]; ++j) {
			pushed[j] += m - i + 1;
		}
	}
	for (int i = p[m - 1]; i < n; ++i) {
		pushed[i]++;
	}

	for (int i = 0; i < n; ++i) {
		result[s[i] - 'a'] += pushed[i];
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		p.resize(m);
		pushed.assign(n, 0);
		result.assign(26, 0);
		cin >> s;

		for (int i = 0; i < m; ++i)
			scanf("%d", &p[i]);
		sort(p.begin(), p.end());
		solve();

		for (int i = 0; i < 26; ++i) {
			printf("%d ", result[i]);
		}
		puts("");
	}

	return 0;
}