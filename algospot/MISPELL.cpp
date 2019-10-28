#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> answers;
	int N;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		int M;
		string line;

		cin >> M >> line;

		answers.push_back(line.substr(0, M-1) + line.substr(M, line.length()-1));
	}

	int i = 1;
	for (vector<string>::iterator iter = answers.begin(); iter < answers.end(); ++iter) {
		cout << i << " " << *iter << endl;
		++i;
	}

	return 0;
}