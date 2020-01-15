#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, m;
vector<int> A, B;
vector<vector<int>> cache;

int calJLIS(int indexA, int indexB) {
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;

	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxE = max(a, b);

	for (int i = indexA + 1; i < n; ++i) {
		if (maxE < A[i])
			ret = max(ret, calJLIS(i, indexB) + 1);
	}

	for (int j = indexB + 1; j < m; ++j) {
		if (maxE < B[j])
			ret = max(ret, calJLIS(indexA, j) + 1);
	}

	return ret;
}

int main() {
	int c, input;
	vector<int> answers;

	cin >> c;
	for (int i = 0; i < c; ++i) {
		cin >> n >> m;

		for (int j = 0; j < n; ++j) {
			cin >> input;
			A.push_back(input);
		}
		for (int j = 0; j < m; ++j) {
			cin >> input;
			B.push_back(input);
		}
		cache.assign(n  + 1, vector<int>(m + 1, -1));
		int maxLen = calJLIS(-1, -1) - 2;
		answers.push_back(maxLen);
		A.clear();
		B.clear();
		cache.clear();
	}

	for (vector<int>::const_iterator it = answers.begin(); it != answers.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}