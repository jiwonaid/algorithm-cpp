#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int solve(int N);
int setQueen(int** board, int r, int c, int N);

int main() {
	vector<int> answers;
	int C;

	cin >> C;

	for (int i = 0; i < C; ++i) {
		int N;
		cin >> N;

		answers.push_back(solve(N));
	}

	for (vector<int>::const_iterator iter = answers.begin(); iter < answers.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}

int solve(int N) {
	int ret = 0;
	int** board = new int* [N];
	for (int k = 0; k < N; ++k) {
			board[k] = new int[N];
			memset(board[k], 0, sizeof(int) * (N));
	}

	for(int i = 0; i < N; ++i)
		ret += setQueen(board, 0, i, N);
		
	for (int i = 0; i < N; ++i) {
			delete[] board[i];
		}
	delete[] board;
	
	return ret;
}

int setQueen(int** oBoard, int r, int c, int N) {
	int ret = 0;
	
	int** board = new int * [N];
	for (int k = 0; k < N; ++k) {
		board[k] = new int[N];
		memcpy(board[k], oBoard[k], sizeof(int) * (N));
	}

	if(board[r][c] == 1) {
		for (int i = 0; i < N; ++i) {
			delete[] board[i];
		}
		delete[] board;
		return 0;
	}

	if (r == (N - 1) && board[r][c] == 0) {

		for (int i = 0; i < N; ++i) {
			delete[] board[i];
		}
		delete[] board;
		return 1;
	}
	
	else {	
		// board[r][c] = 1;
		r += 1;
		
		int right = c;
		int left = c;
		for (int i = r; i < N; ++i) {
			board[i][c] = 1; // i, c
		}
		for (int i = r; i < N; ++i) {
			if (right < N - 1)
				++right;	
			board[i][right] = 1; // +1, +1
			if (right == N - 1)
				break;
		}
		for (int i = r; i < N; ++i) {
			if (left > 0)
				--left;
			board[i][left] = 1; // +1, -1
			if (left == 0)
				break;
		}

		for (int i = 0; i < N; ++i) {
			if(r < N)
				ret += setQueen(board, r, i, N);
		}
		for (int i = 0; i < N; ++i) {
			delete[] board[i];
		}
		delete[] board;

		return ret;
	}
	
}