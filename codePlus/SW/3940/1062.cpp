#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, k, result = 0;
bool dict[50][26], learned[26];
vector<string> words;

void solve(int from, int num) {
	if (num == 0) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cnt++;
			for (int j = 0; j < 26; ++j) {
				if (dict[i][j]) {
					if (!learned[j]) {
						cnt--;
						break;
					}
				}
			}
		}
		result = max(result, cnt);
	}
	else {
		for (int i = from; i < 26; ++i) {
			if (!learned[i]) {
				learned[i] = true;
				solve(i, num - 1);
				learned[i] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	words.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> words[i];
		for (int j = 4; j < words[i].size() - 4; ++j) {
			if (words[i][j] != 'a' && words[i][j] != 'n' && words[i][j] != 't' && words[i][j] != 'i' && words[i][j] != 'c') {
				dict[i][words[i][j] - 'a'] = true;
			}
		}
	}

	// a n t i c
	if (k < 5)
		cout << 0;
	else {
		learned['a' - 'a'] = true;
		learned['n' - 'a'] = true;
		learned['t' - 'a'] = true;
		learned['i' - 'a'] = true;
		learned['c' - 'a'] = true;
		solve(1, k - 5);

		cout << result;
	}

	return 0;
}