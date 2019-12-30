#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> visited;
int boardSize;

void visit(int x, int y) {
	if (visited[x][y] == 1)
		return;
	else {
		visited[x][y] = 1;
		int jump = board[x][y];
		if (x == boardSize - 1 && y == boardSize - 1) {
			return;
		}
		else {
			if (x + jump < boardSize) {
				visit(x + jump, y);
			}
			if (y + jump < boardSize) {
				visit(x, y + jump);
			}
		}
	}
}

string reachable() {
	string ret = "YES";
	visited.assign(boardSize, vector<int>(boardSize, -1));

	visit(0, 0);

	if (visited[boardSize - 1][boardSize - 1] == -1)
		ret = "NO";

	return ret;
}

int main() {
	int C, n, input;
	vector<string> answers;

	cin >> C;
	if (C <= 0)
		exit(EXIT_FAILURE);

	for (int i = 0; i < C; ++i) {
		cin >> n;
		for (int j = 0; j < n; ++j) {
			vector<int> row;

			for (int k = 0; k < n; ++k) {
				cin >> input;
				row.push_back(input);
			}
			board.push_back(row);
		}
		boardSize = board.size();
		answers.push_back(reachable());
		board.clear();
	}

	for (vector<string>::const_iterator i = answers.begin(); i != answers.end(); ++i) {
		cout << *i << endl;
	}

	return 0;
}