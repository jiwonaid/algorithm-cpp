#include <iostream>
#include <vector>

using namespace std;

int calCoins(int M, int C, int coins[]) {
	if (M == 0) {
		return 1;
	}

	if (M < 0) {
		return 0;
	}
	
	if (C <= 0 && M >= 1)
		return 0;

	return calCoins(M, C - 1, coins) + calCoins(M - coins[C - 1], C, coins);
}

int main() {
	vector<int> answers;
	int T;
	int M, C;

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> M >> C;
		int* coins = new int[C];
		for (int j = 0; j < C; ++j) {
			cin >> coins[j];
		}

		int result = calCoins(M, C, coins);
		delete[] coins;
		answers.push_back(result);
	}

	for (vector<int>::const_iterator it = answers.begin(); it != answers.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}