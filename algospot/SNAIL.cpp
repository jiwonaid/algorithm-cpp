#include <iostream>

using namespace std;

int n, m;
double cache[1001][2001];

double climb(int days, int climbed) {
	if (days == m) {
		if (climbed >= n)
			return 1.0;
		else
			return 0;
	}

	double& ret = cache[days][climbed];
	if (ret != -1)
		return ret;

	ret = 0.25 * climb(days + 1, climbed + 1) + 0.75 * climb(days + 1, climbed + 2);
	return ret;
}

int main() {
	int C;

	cin >> C;
	for (int i = 0; i < C; ++i) {
		cin >> n >> m;
		fill(&cache[0][0], &cache[1000][2000], -1);
		
		cout.precision(10);
		cout.setf(ios::fixed, ios::floatfield);
		cout << climb(0, 0) << endl;
	}

	return 0;
}