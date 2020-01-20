#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string pi;
vector<int> cache;

int difficulty(int a, int b) {
	string part = pi.substr(a, b - a + 1);

	if (part == string(part.size(), part[0]))
		return 1;

	bool arithmetic = true;
	for (int i = 0; i < part.size() - 1; ++i) {
		if (part[i + 1] - part[i] != part[1] - part[0])
			arithmetic = false;
	}
	if (arithmetic && abs(part[1] - part[0]) == 1)
		return 2;

	bool alternating = true;
	for (int i = 0; i < part.size(); ++i) {
		if (part[i] != part[i % 2])
			alternating = false;
	}
	if (alternating)
		return 4;
	if (arithmetic)
		return 5;
	return 10;
}

int solve(int point) {
	if (point == pi.size())
		return 0;

	int& ret = cache[point];
	if (ret != -1)
		return ret;

	ret = 98765;
	for (int i = 3; i <= 5; ++i) {
		if (point + i <= pi.size()) {
			ret = min(ret, solve(point + i) + difficulty(point, point + i - 1));
		}
	}

	return ret;
}

int main() {
	int C;

	cin >> C;
	for (int i = 0; i < C; ++i) {
		cin >> pi;
		cache.assign(pi.size(), -1);
		cout << solve(0) << endl;
	}

	return 0;
}