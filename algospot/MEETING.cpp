#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int matchCouple(vector<int> man, vector<int> woman) {
	int min = 0;

	sort(man.begin(), man.end());
	sort(woman.begin(), woman.end());

	for (int i = 0; i < man.size(); ++i) {
		min += abs(man[i] - woman[i]);
	}

	return min;
}

int main() {
	vector<int> answers;
	int T, N;
	
	cin >> T;
	for (int i = 0; i < T; ++i) {
		vector<int> man;
		vector<int> woman;
		int e;
		
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> e;
			man.push_back(e);
		}
		for (int j = 0; j < N; ++j) {
			cin >> e;
			woman.push_back(e);
		}

		answers.push_back(matchCouple(man, woman));
	}

	for (vector<int>::const_iterator it = answers.begin(); it != answers.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}