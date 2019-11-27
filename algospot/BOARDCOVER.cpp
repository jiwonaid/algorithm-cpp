#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

const int dXY[4][3][2] = {
	{{0,0}, {1,0}, {0,1}},
	{{0,0}, {0,1}, {1,1}},
	{{0,0}, {1,0}, {1,1}},
	{{0,0}, {1,0}, {1,-1}}
};

bool set(vector<vector<int>>& board, int x, int y, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; ++i) {
		const int nx = x + dXY[type][i][0];
		const int ny = y + dXY[type][i][1];
		if (nx < 0 || nx >= board.size() ||
			ny < 0 || ny >= board[0].size()) {
			ok = false;
		}
		else if ((board[nx][ny] += delta) > 1) {
			ok = false;
		}
	}
	return ok;
}

int cover(vector<vector<int>>& board) {
	int x = -1, y = -1;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			if (board[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
		if (x != -1) break;
	}

	if (x == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; ++type) {
		if (set(board, x, y, type, 1))
			ret += cover(board);
		set(board, x, y, type, -1);
	}
	return ret;
}

int main() {
	vector<int> answers;
	int C, H, W;
	
	cin >> C;
	for (int i = 0; i < C; ++i) {
		vector<vector<int>> board;
		vector<int> row;
		string input;
		char c;
		int countZero = 0;

		cin >> H >> W;
		for (int j = 0; j < H; ++j) {
			cin >> input;
			
			replace(input.begin(), input.end(), '#', '1');
			replace(input.begin(), input.end(), '.', '0');
			stringstream ss(input);

			while (ss.get(c)) {
				if (c == '0')
					countZero += 1;
				row.push_back(c - '0');
			}
			board.push_back(row);
			row.clear();
		}

		if (countZero % 3 != 0) {
			answers.push_back(0);
		}
		else {
			answers.push_back(cover(board));
		}
	}

	for (vector<int>::const_iterator it = answers.begin(); it != answers.end(); ++it) {
		cout << *it << endl;
	}

}