#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> cache;
vector<int> NGE;

int findIdx(int value, int idx) {
	if (cache[idx] == -1)
		return -1;
	else {
		if (value < arr[cache[idx]]) {
			return cache[idx];
		}
		else
			return findIdx(value, cache[idx]);
	}
}

int main() {
	int N, input;

	cin >> N;
	cache = vector<int>(N, -1);
	for (int i = 0; i < N; ++i) {
		cin >> input;
		arr.push_back(input);
	}

	for (int i = N - 2; i > -1; --i) {
		if (arr[i] < arr[i + 1]) {
			cache[i] = i + 1;
			NGE.push_back(arr[i + 1]);
		}
		else {
			int temp = findIdx(arr[i], i + 1);
			cache[i] = temp;
			temp == -1 ? NGE.push_back(temp) : NGE.push_back(arr[temp]);
		}
	}

	for (auto it = NGE.crbegin(); it != NGE.crend(); ++it)
		cout << *it << ' ';
	cout << -1;

	return 0;
}