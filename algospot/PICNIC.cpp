#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(int n, int m, vector<pair<int, int>> friends) {
	int ret = 0;
	if (n < 2 || m < 1 || m < (n / 2))
		return ret;
	vector<bool> picked(n);
	fill(picked.begin(), picked.end(), false);
	vector<bool> v(m);
	fill(v.end() - (n / 2), v.end(), true);

	do {
		bool okay = true;
		fill(picked.begin(), picked.end(), false);

		for (int i = 0; i < m; ++i) {
			if (v[i]) {
				if (picked[friends[i].first] || picked[friends[i].second]) {
					okay = false;
					break;
				}
				else {
					picked[friends[i].first] = true;
					picked[friends[i].second] = true;
				}
			}
		}
		if (okay) {
			ret += 1;
		}
	} while (next_permutation(v.begin(), v.end()));

	return ret;
}

int main() {
	vector<int> answers;
	int C, n, m, input1, input2;
	
	cin >> C;
	for (int i = 0; i < C; ++i) {
		vector<pair<int, int>> friends;

		cin >> n >> m;
		for (int j = 0; j < m; ++j) {
			cin >> input1 >> input2;
			friends.push_back(make_pair(input1, input2));
		}
		answers.push_back(calc(n, m, friends));
	}

	for (vector<int>::const_iterator it = answers.begin(); it != answers.end(); ++it) {
		cout << *it << endl;
	}

}