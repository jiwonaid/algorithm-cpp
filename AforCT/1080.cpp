#pragma warning(disable : 4996)

#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> c;

void operation(int x, int y) {
	for (int i = x; i < x + 3; ++i) {
		for (int j = y; j < y + 3; ++j) {
			c[i][j] = !c[i][j];
		}
	}
}

int main() {
	int n, m, count = 0; scanf("%d %d", &n, &m);
	vector<vector<int>> a(vector<vector<int>>(n, vector<int>(m)));
	vector<vector<int>> b(vector<vector<int>>(n, vector<int>(m)));
	c = vector<vector<bool>>(n, vector<bool>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &b[i][j]);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] == b[i][j] ? c[i][j] = true : c[i][j] = false;
		}
	}
	
	for (int i = 0; i <= n - 3; ++i) {
		for (int j = 0; j <= m - 3; ++j) {
			if (!c[i][j]) {
				operation(i, j);
				count++;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!c[i][j]) {
				count = -1;
				break;
			}
		}
	}

	printf("%d", count);

	return 0;
}