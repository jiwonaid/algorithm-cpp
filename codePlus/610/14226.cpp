#pragma warning(disable : 4996)

#include <iostream>
#include <algorithm>

using namespace std;

int s;
int arr[1001][1001];

void solve(int n, int clip, int cnt) {
	if ( n > 1000 || n < clip || cnt > 1000)
		return;

	int& ret = arr[n][clip];
	if (ret > cnt) {
		ret = cnt;
		solve(n, n, cnt + 1);
		solve(n + clip, clip, cnt + 1);
		solve(n - 1, clip, cnt + 1);
	}
}

int main() {
	scanf("%d", &s);
	fill(&arr[0][0], &arr[0][0] + (1001 * 1001), 1001);

	solve(1, 0, 0);
	int result = 1001;
	for (int i = 0; i < s; ++i)
		result = min(result, arr[s][i]);

	printf("%d", result);

	return 0;
}