#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string S;
	vector<string> arr;

	cin >> S;
	for (int i = 0; i < S.length(); ++i) {
		arr.push_back(S.substr(i, S.length() - i));
	}
	sort(arr.begin(), arr.end());

	auto it = arr.cbegin();
	while (it != arr.cend()) {
		cout << *it << endl;
		it++;
	}

	return 0;
}