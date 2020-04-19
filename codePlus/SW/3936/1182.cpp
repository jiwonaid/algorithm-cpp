#pragma warning(disable : 4996)

#include <iostream>
#include <vector>

using namespace std;

int n, s, cnt = 0;
vector<int> v;

void solve(int pos, int temp) {
	if (pos == n) {
		if(temp == s)
			cnt++;
		return;
	}
	else {
		solve(pos + 1, temp);
		solve(pos + 1, temp + v[pos]);
	}
}

int main() {
	scanf("%d %d", &n, &s);
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &v[i]);
	}

	solve(0, 0);
	if (s == 0)
		cnt--;
	printf("%d", cnt);

	return 0;
}