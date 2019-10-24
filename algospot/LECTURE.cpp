#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	vector<string> results;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		string line;
		vector<string> sorter;

		cin >> line;

		for (int i = 0; i < line.length(); i += 2) {
			sorter.push_back(line.substr(i, 2));
		}
		sort(sorter.begin(), sorter.end());

		line = "";
		for (vector<string>::iterator iter = sorter.begin(); iter < sorter.end(); ++iter) {
			line.append(*iter);
		}

		results.push_back(line);
	}

	for (vector<string>::iterator iter = results.begin(); iter < results.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}