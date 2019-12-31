#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;
string wild, name;

bool isMatched(int w, int n) {
	int& ret = dp[w][n];

	if (ret != -1)
		return ret;
	while (w < wild.length() && n < name.length() && (wild[w] == '?' || wild[w] == name[n])) {
		++w;
		++n;
	}

	if (w == wild.length()) {
		return ret = (n == name.length());
	}

	if(wild[w] == '*')
		for (int skip = 0; n + skip <= name.size(); ++skip) {
			if (isMatched(w + 1, n + skip)) {
				return ret = 1;
			}
		}

	return ret = 0;
}

string getNames(string W, vector<string> fNames) {
	string ret;
	vector<string> result;
	
	wild = W;
	for (vector<string>::const_iterator i = fNames.begin(); i != fNames.end(); ++i) {
		dp.assign(101, vector<int>(101, -1));
		name = *i;
		if (isMatched(0, 0))
			result.push_back(name);
	}
	sort(result.begin(), result.end());

	for (vector<string>::const_iterator i = result.begin(); i != result.end(); ++i) {
		ret += *i + "\n";
	}

	return ret;
}

int main() {
	int C, N;
	string W, input;
	vector<string> answers, fNames;

	cin >> C;
	for (int i = 0; i < C; ++i) {
		cin >> W;
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> input;
			fNames.push_back(input);
		}
		answers.push_back(getNames(W, fNames));
		fNames.clear();
	}

	for (vector<string>::const_iterator i = answers.begin(); i != answers.end(); ++i) {
		cout << *i;
	}

	return 0;
}