#include <iostream>
#include <vector>

using namespace std;

string decode(string line);
vector<pair<string, string>> encodings;

int main() {
	vector<string> answers;
	int C;

	encodings.push_back(make_pair("%20", " "));
	encodings.push_back(make_pair("%21", "!"));
	encodings.push_back(make_pair("%24", "$"));
	// encodings.push_back(make_pair("%25", "%"));
	encodings.push_back(make_pair("%28", "("));
	encodings.push_back(make_pair("%29", ")"));
	encodings.push_back(make_pair("%2a", "*"));

	encodings.push_back(make_pair("%25", "%"));

	cin >> C;

	for (int i = 0; i < C; ++i) {
		string line;
		cin >> line;

		line = decode(line);

		answers.push_back(line);
	}

	for (vector<string>::iterator iter = answers.begin(); iter < answers.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}

string decode(string line) {
	string replacement;

	for (int i = 0; i < encodings.size(); ++i) {
		for (int pos = 0; pos < line.length(); ++pos) {
			if (line.substr(pos, 3) == encodings[i].first) {
				replacement = encodings[i].second;
				line = line.replace(pos, 3, replacement);
			}
		}
	}

	return line;
}