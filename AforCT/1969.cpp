#pragma warning(disable : 4996)

#include <iostream>
#include <vector>

using namespace std;

int toIdx(char input) {
	if (input == 'A')
		return 0;
	if (input == 'C')
		return 1;
	if (input == 'G')
		return 2;
	else
		return 3;
}

char toChar(int input) {
	if (input == 0)
		return 'A';
	if (input == 1)
		return 'C';
	if (input == 2)
		return 'G';
	else
		return 'T';
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	char input;
	// A C G T
	vector<vector<int>> arr(m, vector<int>(4));
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf(" %c", &input);
			arr[j][toIdx(input)]++;
		}
	}

	int idx, pSum, sum = 0;
	string result;
	for (int i = 0; i < m; ++i) {
		idx = 0;
		pSum = arr[i][0];
		for (int j = 1; j < 4; ++j) {
			if (pSum < arr[i][j]) {
				idx = j;
				pSum = arr[i][j];
			}
		}
		result += toChar(idx);
		sum += n - pSum;
	}

	cout << result << '\n';
	cout << sum << '\n';

	return 0;
}