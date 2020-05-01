#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m, result = 11;
pair<int, int> red, blue, hole;
int up(vector<vector<char>> board, pair<int, int> red, pair<int, int> blue, int cnt);
int down(vector<vector<char>> board, pair<int, int> red, pair<int, int> blue, int cnt);
int l(vector<vector<char>> board, pair<int, int> red, pair<int, int> blue, int cnt);
int r(vector<vector<char>> board, pair<int, int> red, pair<int, int> blue, int cnt);

void move(vector<vector<char>>& board, pair<int, int>& marble, int dx, int dy) {
	int x = marble.first, y = marble.second;
	char value = board[x][y];

	while (true) {
		if (board[x + dx][y + dy] == '.') {
			x += dx;
			y += dy;
		}
		else if (board[x + dx][y + dy] == 'O') {
			x += dx;
			y += dy;
			break;
		}
		else
			break;
	}
	board[marble.first][marble.second] = '.';
	if(board[x][y] != 'O') 
		board[x][y] = value;
	marble = { x, y };
}

int up(vector<vector<char>> board, pair<int, int> red, pair<int, int> blue, int cnt) {
	if (cnt == result)
		return 11;
	
	if (red.second > blue.second) {
		move(board, red, 0, 1);
		move(board, blue, 0, 1);
	}
	else {
		move(board, blue, 0, 1);
		move(board, red, 0, 1);
	}

	if (blue == hole)
		return 11;
	else if (red == hole)
		return cnt;
	else
		return min(l(board, red, blue, cnt + 1), r(board, red, blue, cnt + 1));
}

int down(vector<vector<char>> board, pair<int, int> red, pair<int, int> blue, int cnt) {
	if (cnt == result)
		return 11;

	if (red.second < blue.second) {
		move(board, red, 0, -1);
		move(board, blue, 0, -1);
	}
	else {
		move(board, blue, 0, -1);
		move(board, red, 0, -1);
	}

	if (blue == hole)
		return 11;
	else if (red == hole)
		return cnt;
	else
		return min(l(board, red, blue, cnt + 1), r(board, red, blue, cnt + 1));
}

int l(vector<vector<char>> board, pair<int, int> red, pair<int, int> blue, int cnt) {
	if (cnt == result)
		return 11;

	if (red.first < blue.first) {
		move(board, red, -1, 0);
		move(board, blue, -1, 0);
	}
	else {
		move(board, blue, -1, 0);
		move(board, red, -1, 0);
	}

	if (blue == hole)
		return 11;
	else if (red == hole)
		return cnt;
	else
		return min(up(board, red, blue, cnt + 1), down(board, red, blue, cnt + 1));
}

int r(vector<vector<char>> board, pair<int, int> red, pair<int, int> blue, int cnt) {
	if (cnt == result)
		return 11;

	if (red.first > blue.first) {
		move(board, red, 1, 0);
		move(board, blue, 1, 0);
	}
	else {
		move(board, blue, 1, 0);
		move(board, red, 1, 0);
	}

	if (blue == hole)
		return 11;
	else if (red == hole)
		return cnt;
	else
		return min(up(board, red, blue, cnt + 1), down(board, red, blue, cnt + 1));
}

int solve(vector<vector<char>>& board, int cnt) {
	result = min(result, up(board, red, blue, cnt + 1));
	result = min(result, down(board, red, blue, cnt + 1));
	result = min(result, l(board, red, blue, cnt + 1));
	result = min(result, r(board, red, blue, cnt + 1));

	return result;
}

int main () {
	scanf("%d %d", &n, &m);
	vector<vector<char>> board = vector<vector<char>>(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf(" %1c", &board[i][j]);
			if (board[i][j] == 'R')
				red = { i, j };
			else if (board[i][j] == 'B')
				blue = { i, j };
			else if (board[i][j] == 'O')
				hole = { i, j };
		}
	}

	solve(board, 0);
	if (result == 11)
		result = -1;
	printf("%d", result);

	return 0;
}