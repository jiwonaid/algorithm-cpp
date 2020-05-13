#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int n, result = 0;
vector<vector<int>> board;

int getLargest(vector<vector<int>>& board, int temp) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			temp = max(temp, board[i][j]);
		}
	}

	return temp;
}

void up(vector<vector<int>>& board) {
	for (int j = 0; j < n; ++j) {
		list<int> temp;
		for (int i = 0; i < n; ++i) {
			if (board[i][j] != 0)
				temp.push_back(board[i][j]);
		}
		if (!temp.empty()) {
			for (auto it = temp.begin(); it != --temp.end(); it++) {
				if (*it == *(next(it))) {
					temp.erase(it++);
					*it += *it;
				}
				if (it == --temp.end())
					break;
			}
		}
		auto it = temp.begin();
		for (int i = 0; i < n; ++i) {
			if (it != temp.end()) {
				board[i][j] = *it;
				it++;
			}
			else
				board[i][j] = 0;
		}
	}
}

void down(vector<vector<int>>& board) {
	for (int j = 0; j < n; ++j) {
		list<int> temp;
		for (int i = n - 1; i >= 0; --i) {
			if (board[i][j] != 0)
				temp.push_back(board[i][j]);
		}
		if (!temp.empty()) {
			for (auto it = temp.begin(); it != --temp.end(); it++) {
				if (*it == *(next(it))) {
					temp.erase(it++);
					*it += *it;
				}
				if (it == --temp.end())
					break;
			}
		}
		auto it = temp.begin();
		for (int i = n - 1; i >= 0; --i) {
			if (it != temp.end()) {
				board[i][j] = *it;
				it++;
			}
			else
				board[i][j] = 0;
		}
	}
}

void l(vector<vector<int>>& board) {
	for (int i = 0; i < n; ++i) {
		list<int> temp;
		for (int j = 0; j < n; ++j) {
			if (board[i][j] != 0)
				temp.push_back(board[i][j]);
		}
		if (!temp.empty()) {
			for (auto it = temp.begin(); it != --temp.end(); it++) {
				if (*it == *(next(it))) {
					temp.erase(it++);
					*it += *it;
				}
				if (it == --temp.end())
					break;
			}
		}
		auto it = temp.begin();
		for (int j = 0; j < n; ++j) {
			if (it != temp.end()) {
				board[i][j] = *it;
				it++;
			}
			else
				board[i][j] = 0;
		}
	}
}

void r(vector<vector<int>>& board) {
	for (int i = 0; i < n; ++i) {
		list<int> temp;
		for (int j = n - 1; j >= 0; --j) {
			if (board[i][j] != 0)
				temp.push_back(board[i][j]);
		}
		if (!temp.empty()) {
			for (auto it = temp.begin(); it != --temp.end(); it++) {
				if (*it == *(next(it))) {
					temp.erase(it++);
					*it += *it;
				}
				if (it == --temp.end())
					break;
			}
		}
		auto it = temp.begin();
		for (int j = n - 1; j >= 0; --j) {
			if (it != temp.end()) {
				board[i][j] = *it;
				it++;
			}
			else
				board[i][j] = 0;
		}
	}
}

void moveBoard(vector<vector<int>> board, int cnt, int dir) {
	if (cnt == 5) {
		result = max(result, getLargest(board, result));
		return;
	}
	else {
		if (dir == 0)
			up(board);
		else if (dir == 1)
			down(board);
		else if (dir == 2)
			l(board);
		else
			r(board);
		for (int i = 0; i < 4; ++i)
			moveBoard(board, cnt + 1, i);
	}
}

int main() {
	scanf("%d", &n);
	board.resize(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0; i < 4; ++i)
		moveBoard(board, 0, i);
	printf("%d", result);

	return 0;
}