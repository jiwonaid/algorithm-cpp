#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	int T;
	string line;
	stack<char> reverse;

	cin >> T;
	cin.ignore();
	while (T--) {
		getline(cin, line);
		for (int i = 0; i < line.size(); ++i) {
			if(line[i] != ' ') {
			reverse.push(line[i]);
			}
			if(line[i] == ' ' || i == line.size() - 1) {
				while (!reverse.empty()) {
					cout << reverse.top();
					reverse.pop();
				}
				cout << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}