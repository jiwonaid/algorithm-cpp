#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c;
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { -1, 1, 0, 0 };
int arr[26];
vector<vector<char>> board;

int solve(int x, int y, int n) {
	int ret = 0;
	if (x < 0 || x >= r || y < 0 || y >= c || arr[board[x][y] - 'A'])
		return n;
	else {
		arr[board[x][y] - 'A'] = 1;
		for (int i = 0; i < 4; ++i) {
			ret = max(ret, solve(x + dx[i], y + dy[i], n + 1));
		}
		arr[board[x][y] - 'A'] = 0;
	}

	return ret;
}

int main() {
	scanf("%d %d", &r, &c);
	board = vector<vector<char>>(r, vector<char>(c));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			scanf(" %c", &board[i][j]);
		}
	}

	printf("%d", solve(0, 0, 0));

	return 0;
}