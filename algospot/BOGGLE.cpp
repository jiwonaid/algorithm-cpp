#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char board[5][5];
bool dpVisited[5][5][10];
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

bool inRange(int x, int y) {
	if (x == -1 || x == 5 || y == -1 || y == 5)
		return false;
	return true;
}

bool hasWord(int x, int y, const string& word, int pos) {
	dpVisited[x][y][pos] = true;
	
	if (board[x][y] != word[0]) return false;

	if (word.size() == 1) return true;

	for (int direction = 0; direction < 8; ++direction) {
		int nextX = x + dx[direction];
		int nextY = y + dy[direction];

		if (inRange(nextX, nextY)) {
			if (dpVisited[nextX][nextY][pos + 1] == true)
				continue;

			if (hasWord(nextX, nextY, word.substr(1), pos + 1))
				return true;
		}
	}
	return false;
}

bool search(const string& input) {
	for (int x = 0; x < 5; ++x) {
		for (int y = 0; y < 5; ++y) {
			if (hasWord(x, y, input, 0) ) {
				return true;
			}
			else
				continue;
		}
	}
	return false;
}

int main() {
	vector<string> answers;
	
	int C, N;
	string input;

	cin >> C;
	for (int i = 0; i < C; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> input;
			input.copy(board[j], input.size());
		}
		cin >> N;
		for (int j = 0; j < N; ++j) {
			memset(dpVisited, false, sizeof(bool) * 5 * 5 * 10);
			cin >> input;
			search(input) ? answers.push_back(input + " YES") : answers.push_back(input + " NO");
		}
	}

	for (vector<string>::const_iterator it = answers.begin(); it < answers.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}