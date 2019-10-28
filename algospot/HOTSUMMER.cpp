#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> answers;
	int T;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		int W, sum = 0;
		cin >> W;

		for (int j = 0; j < 9; ++j) {
			int used;
			cin >> used;
			sum += used;
		}
		if (sum > W)
			answers.push_back("NO");
		else
			answers.push_back("YES");
	}

	for (vector<string>::iterator iter = answers.begin(); iter < answers.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}