#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse(const string& input) {
	string ret = "";
	string arr[4];
	int count = 0;

	if (input.size() == 1)
		return ret = input[0];

	for (int j = 0; j < input.size(); ++j) {
		if (count == 4) {
			break;
		}
		else if (input[j] == 'x') {
			arr[count] = 'x' + reverse(input.substr(j + 1, input.size() - (j + 1)));
			j = j + arr[count].size() - 1;
			count += 1;
		}
		else {
			arr[count] = input[j];
			count += 1;
		}
	}
	ret = arr[2] + arr[3] + arr[0] + arr[1];
	return ret;
}

int main() {
	vector<string> answers;
	int C;
	string input;

	cin >> C;
	
	for (int i = 0; i < C; ++i) {
		cin >> input;
		answers.push_back(reverse(input));
	}

	for (vector<string>::const_iterator ci = answers.begin(); ci != answers.end(); ++ci) {
		cout << *ci << endl;
	}

	return 0;
}