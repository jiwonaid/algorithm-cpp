#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tri;
int cache[100][100];

int triMax(int x, int y) {
	if (x == tri.size() || y == tri.size()) {
		return 0;
	}

	int& ret = cache[x][y];
	if (ret != -1)
		return ret;

	ret = max(tri[x][y] + triMax(x + 1, y), tri[x][y] + triMax(x + 1, y + 1));

	return ret;
}

int triCount(int x, int y) {
	int ret = 0;

	if (x == tri.size() - 1 && y < tri.size())
		return 1;

	if (cache[x + 1][y] > cache[x + 1][y + 1]) {
		ret = triCount(x + 1, y);
	}
	else if (cache[x + 1][y] < cache[x + 1][y + 1]) {
		ret = triCount(x + 1, y + 1);
	}
	else {
		ret = triCount(x + 1, y) + triCount(x + 1, y + 1);
	}

	return ret;
}

int main() {
	int C, n, input;

	cin >> C;
	for (int i = 0; i < C; ++i) {
		cin >> n;
		for (int j = 1; j < n + 1; ++j) {
			vector<int> row;
			for (int k = 0; k < j; ++k) {
				cin >> input;
				row.push_back(input);
			}
			tri.push_back(row);
		}
		fill(&cache[0][0], &cache[0][0] + 100 * 100, -1);
		triMax(0, 0);
		cout << triCount(0, 0) << endl;
		tri.clear();
	}

	return 0;
}