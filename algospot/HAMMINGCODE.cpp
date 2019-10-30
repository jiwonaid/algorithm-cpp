#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string> answers;
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		string line;
		cin >> line;

		unsigned int input = (unsigned int) stoi(line, nullptr, 2);
		unsigned int syndrome = 0;

		syndrome += ((input >> 6) ^ (input >> 4) ^ (input >> 2) ^ input) & 1;
		syndrome += (((input >> 5) ^ (input >> 4) ^ (input >> 1) ^ input) & 1) * 2;
		syndrome += (((input >> 3) ^ (input >> 2) ^ (input >> 1) ^ input) & 1) * 4;

		if(syndrome != 0)
			input ^= (1 << (7 - syndrome));

		string result;
		result += ((input >> 4) & 1) ? "1" : "0";
		result += ((input >> 2) & 1) ? "1" : "0";
		result += ((input >> 1) & 1) ? "1" : "0";
		result += (input & 1) ? "1" : "0";

		answers.push_back(result);
	}

	for (vector<string>::const_iterator iter = answers.begin(); iter < answers.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}