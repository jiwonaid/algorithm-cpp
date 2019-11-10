#include <iostream>
#include <vector>

using namespace std;

int calcMax(const vector<int> arr) {
	int max = 0, currentM = 0;

	for (vector<int>::const_iterator it = arr.begin(); it != arr.end(); ++it) {
		currentM += *it;
		if (currentM < 0)
			currentM = 0;
		else if (max < currentM)
			max = currentM;
	}

	return max;
}

int main() {
	vector<int> answers;
	int T, N;
	
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		int e;
		vector<int> arr;
		for (int j = 0; j < N; ++j) {
			cin >> e;
			arr.push_back(e);
		}

		answers.push_back(calcMax(arr));
	}

	for (vector<int>::const_iterator it = answers.begin(); it != answers.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}