#include <iostream>
#include <vector>

using namespace std;

int calcMax(vector<int> fence) {
	int ret = 0;

	if (fence.size() == 1) {
		ret = fence[0];
	}
	else {
		for (int i = 0; i < fence.size(); ++i) {
			int temp = 0;
			int lLength = i;
			for (int j = i; j > -1; --j) {
				if (fence[i] > fence[j]) {
					lLength = i - j - 1;
					break;
				}
			}
			int rLength = fence.size() - i;
			for (int j = i; j < fence.size(); ++j) {
				if (fence[i] > fence[j]) {
					rLength = j - i;
					break;
				}
			}
			temp = fence[i] * lLength + fence[i] * rLength;
			if (ret < temp)
				ret = temp;
		}
	}

	return ret;
}

int main() {
	vector<int> answers;
	int C, N;
	
	cin >> C;
	for (int i = 0; i < C; ++i) {
		vector<int> fence;
		int input;

		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> input;
			fence.push_back(input);
		}
		answers.push_back(calcMax(fence));
	}

	for (vector<int>::const_iterator ci = answers.begin(); ci != answers.end(); ++ci) {
		cout << *ci << endl;
	}

	return 0;
}