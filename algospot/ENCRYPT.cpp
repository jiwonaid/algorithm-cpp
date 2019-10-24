#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	vector<string> results;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		string inputLine;
		string evenLine = "";
		string oddLine = "";
		string ret;

		cin >> inputLine;

		for (int i = 0; i < inputLine.length(); ++i) {
			if (i % 2 == 0)
				evenLine += inputLine[i];
			else
				oddLine += inputLine[i];
		}
		ret = evenLine + oddLine;
		results.push_back(ret);
	}

	for (vector<string>::iterator iter = results.begin(); iter < results.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}