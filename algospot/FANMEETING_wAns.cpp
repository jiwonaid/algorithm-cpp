#include <iostream>
#include <vector>

using namespace std;

int calc(string members, string fans) {
	int ret = 0;
	bool okay = true;

	for (int i = 0; i < (fans.length() - members.length() + 1); ++i) {
		okay = true;
		for (int j = 0; j < members.length(); ++j) {
			if (members[j] == 'M' && fans[i + j] == 'M') {
				okay = false;
				break;
			}
		}
		if (okay)
			ret += 1;
	}

	return ret;
}

int main() {
	vector<int> answers;
	int C;
	
	cin >> C;
	for (int i = 0; i < C; ++i) {
		string members;
		string fans;
		
		cin >> members >> fans;

		answers.push_back(calc(members, fans));
	}

	for (vector<int>::const_iterator ci = answers.begin(); ci != answers.end(); ++ci) {
		cout << *ci << endl;
	}

	return 0;
}