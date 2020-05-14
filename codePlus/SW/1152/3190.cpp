#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<bool>> board;
vector<vector<bool>> isSnake;
deque<pair<int, int>> snake;
queue<pair<int, char>> movement;

int solve(int x, int y, int dx, int dy, int cnt) {
	int nextX = x + dx, nextY = y + dy;
	if (nextX == -1 || nextX == n || nextY == -1 || nextY == n || isSnake[nextX][nextY])
		return cnt;
	else {
		isSnake[nextX][nextY] = true;
		snake.push_front({ nextX, nextY });

		if (board[nextX][nextY]) {
			board[nextX][nextY] = false;
		}
		else {
			pair<int, int> tail = snake.back();
			isSnake[tail.first][tail.second] = false;
			snake.pop_back();
		}

		if (!movement.empty() && movement.front().first == cnt) {
			char dir = movement.front().second;
			if ((dx == -1 && dir == 'L') || (dx == 1 && dir == 'D')) {
				dx = 0;
				dy = -1;
			}
			else if ((dx == -1 && dir == 'D') || (dx == 1 && dir == 'L')) {
				dx = 0;
				dy = 1;
			}
			else if ((dy == -1 && dir == 'D') || (dy == 1 && dir == 'L')) {
				dx = -1;
				dy = 0;
			}
			else if ((dy == -1 && dir == 'L') || (dy == 1 && dir == 'D')) {
				dx = 1;
				dy = 0;
			}
			movement.pop();
		}

		return solve(nextX, nextY, dx, dy, cnt + 1);
	}
}

int main() {
	scanf("%d", &n);
	board.resize(n, vector<bool>(n));
	isSnake.resize(n, vector<bool>(n));
	int k; scanf("%d", &k);
	int r, c;
	for (int i = 0; i < k; ++i) {
		scanf("%d %d", &r, &c);
		board[r - 1][c - 1] = true;
	}
	int l; scanf("%d", &l);
	int time; char dir;
	for (int i = 0; i < l; ++i) {
		scanf("%d %c", &time, &dir);
		movement.push({ time, dir });
	}

	snake.push_back({ 0, 0 });
	isSnake[0][0] = true;
	printf("%d", solve(0, 0, 0, 1, 1));

	return 0;
}