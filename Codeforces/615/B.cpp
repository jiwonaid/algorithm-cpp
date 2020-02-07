#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	int t, n, x, y;
	set<pair<int, int>> set;

	cin >> t;
	while (t--) {
		set.clear();
		cin >> n;
		while (n--) {
			cin >> x >> y;
			set.insert(make_pair(x, y));
		}

		int preX = 0, preY = 0;
		string result = "YES\n";

		for (auto&& i : set) {
			if (i.first < preX || i.second < preY) {
				result = "NO";
				break;
			}
			while (i.first > preX) {
				preX++;
				result += 'R';
			}
			while (i.second > preY) {
				preY++;
				result += 'U';
			}
		}
		cout << result << endl;
	}

	return 0;
}