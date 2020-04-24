#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

vector<string> arr;
int alp[26];

int main() {
	int n; cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		for (int j = 0; j < arr[i].size(); ++j) {
			alp[arr[i][j] - 'A'] += pow(10, arr[i].size() - j - 1);
		}
	}
	sort(alp, alp + 26, greater<int>());

	int result = 0;
	for (int i = 0; alp[i]; ++i) {
		result += alp[i] * (9 - i);
	}
	cout << result;

	return 0;
}