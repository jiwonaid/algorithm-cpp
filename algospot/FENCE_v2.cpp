#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fence;

int calcMax(int left, int right) {

	if (left == right)
		return fence[left];

	// Left and right
	int mid = (left + right) / 2;
	int ret = max(calcMax(left, mid), calcMax(mid + 1, right));

	// Middle
	int lo = mid, hi = mid + 1;
	int height = min(fence[lo], fence[hi]);

	ret = max(ret, height * 2);
	
	while (left < lo || hi < right) {
		if (hi < right && (lo == left || fence[lo - 1] < fence[hi + 1])) {
			++hi;
			height = min(height, fence[hi]);
		}
		else {
			--lo;
			height = min(height, fence[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;

}

int main() {
	vector<int> answers;
	int C, N;

	cin >> C;
	for (int i = 0; i < C; ++i) {
		int input;

		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> input;
			fence.push_back(input);
		}
		answers.push_back(calcMax(0, fence.size() - 1));
		fence.clear();
	}

	for (vector<int>::const_iterator ci = answers.begin(); ci != answers.end(); ++ci) {
		cout << *ci << endl;
	}

	return 0;
}