#include <iostream>
#include <vector>

using namespace std;

int main() {
	int C;
	vector<string> names;

	cin >> C;

	for (int i = 0; i < C; ++i) {
		string name;
		cin >> name;
		names.push_back(name);
	}

	for (vector<string>::iterator iter = names.begin(); iter != names.end(); ++iter) {
		cout << "Hello, " << *iter << "!" << endl;
	}

	return 0;
}