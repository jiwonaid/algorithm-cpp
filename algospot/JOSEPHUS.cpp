#include<iostream>
#include<vector>

using namespace std;

vector<int> survivors(int N, int K) {
	vector<int> people;

	for (int i = 1; i < N + 1; ++i) {
		people.push_back(i);
	}
	
	vector<int>::iterator it = people.begin();
	for (int i = 0; i < N - 2; ++i) {
		if (it == people.end()) {
			it = people.begin();
		}
		it = people.erase(it);

		for (int j = 0; j < K - 1; ++j) {
			if (it == people.end()) {
				it = people.begin();
			}
			++it;
		}
	}

	return people;
}

int main() {
	int C, N, K;

	cin >> C;
	for (int i = 0; i < C; ++i) {
		cin >> N >> K;
		vector<int> result = survivors(N, K);
		cout << result[0] << " " << result[1] << endl;
	}

	return 0;
}