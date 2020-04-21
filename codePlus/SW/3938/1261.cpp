#pragma warning(disable : 4996)

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m, n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[100][100];
bool visited[100][100];

int BFS() {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, { 0 , 0 } });
	visited[0][0]= true;
	
	int x, y, cnt;
	while (!pq.empty()) {
		x = pq.top().second.first;
		y = pq.top().second.second;
		cnt = pq.top().first;
		pq.pop();

		if (x == n - 1 && y == m - 1)
			return cnt;

		int nextX, nextY;
		for (int i = 0; i < 4; ++i) {
			nextX = x + dx[i];
			nextY = y + dy[i];
			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
				if (!visited[nextX][nextY]) {
					if (board[nextX][nextY] == 1)
						pq.push({ cnt + 1,{ nextX, nextY } });
					else
						pq.push({ cnt, {nextX, nextY} });
					visited[nextX][nextY] = true;
				}
			}
		}

	}
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%1d", &board[i][j]);
		}
	}

	printf("%d", BFS());
	
	return 0;
}