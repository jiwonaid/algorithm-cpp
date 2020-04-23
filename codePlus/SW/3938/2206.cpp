#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector<vector<int>> board;
vector<vector<vector<int>>> cache;

int BFS() {
	queue<pair<pair<int, int>, int>> mq;
	mq.push({ { 0, 0 }, 1 });
	cache[0][0][1] = 1;

	int x, y, destroy, nextX, nextY;
	while (!mq.empty()) {
		x = mq.front().first.first;
		y = mq.front().first.second;
		destroy = mq.front().second;
		mq.pop();

		if (x == n - 1 && y == m - 1)
			return cache[x][y][destroy];

		for (int i = 0; i < 4; ++i) {
			nextX = x + dx[i];
			nextY = y + dy[i];
			
			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
				if (board[nextX][nextY] && destroy) {
					cache[nextX][nextY][0] = cache[x][y][1] + 1;
					mq.push({ {nextX, nextY}, 0 });
				}
				if (!board[nextX][nextY] && !cache[nextX][nextY][destroy]) {
					cache[nextX][nextY][destroy] = cache[x][y][destroy] + 1;
					mq.push({ {nextX, nextY}, destroy });
				}
			}
		}
	}

	return -1;
}

int main() {
	scanf("%d %d", &n, &m);
	board = vector<vector<int>>(n, vector<int>(m));
	cache = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(2)));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &board[i][j]);
		}
	}

	printf("%d", BFS());
	
	return 0;
}