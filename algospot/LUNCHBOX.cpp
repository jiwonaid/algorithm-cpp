#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcLunchTime(int micro[], int eat[], int N) {
	int mTime = 0, eTime = 0, ret = 0;
	vector<pair<int, int>> times;
	
	for (int i = 0; i < N; ++i) {
		times.push_back(make_pair(eat[i], micro[i]));
	}
	sort(times.begin(), times.end(), greater<pair<int, int>>());
	
	for (vector<pair<int, int>>::const_iterator it = times.begin(); it != times.end(); ++it) {
		mTime += (*it).second;
		ret = max(ret, mTime + (*it).first);
	}

	return ret;
}

int main() {
	vector<int> answers;
	int T, N;
	
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;

		int* micro = new int[N];
		int* eat = new int[N];
		for (int j = 0; j < N; ++j) {
			cin >> micro[j];
		}
		for (int j = 0; j < N; ++j) {
			cin >> eat[j];
		}

		answers.push_back(calcLunchTime(micro, eat, N));
		delete[] micro;
		delete[] eat;
	}

	for (vector<int>::const_iterator it = answers.begin(); it != answers.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}