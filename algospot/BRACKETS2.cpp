#include <iostream>
#include <vector>

using namespace std;

int main() {
	string answers;
	int C;
	cin >> C;

	for (int i = 0; i < C; ++i) {
		string line, result = "NO";
		cin >> line;

		vector<char> v;
		
		for (int j = 0; j < line.length(); ++j) {
			if (!v.empty() && ((v.back() == line.at(j) - 1) || (v.back() == line.at(j) - 2)))
				v.pop_back();
			else
				v.push_back(line.at(j));
		}

		int isVChanged;
		while (v.size()) {
			isVChanged = v.size();
			for (vector<char>::iterator iter = v.begin(); (iter + 1) != v.end(); ++iter) {
				if ((*iter == *(iter + 1) - 1) || (*iter == *(iter + 1) - 2)) {
					v.erase(iter);
					v.erase(iter + 1);
				}
			}
			if (isVChanged == v.size())
				break;
		}

		if (v.empty())
			result = "YES";

		answers += result + "\n";
	}

	cout << answers;

	return 0;
}