#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;

	cin >> T;

	int x1, y1, x2, y2, x3, y3, x4, y4;
	vector<pair<int, int>> results;

	for (int i = 0; i < T; ++i) {
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cin >> x3 >> y3;

		if (x2 == x3)
			x4 = x1;
		else if (x1 == x3)
			x4 = x2;
		else
			x4 = x3;

		if (y2 == y3)
			y4 = y1;
		else if (y1 == y3)
			y4 = y2;
		else
			y4 = y3;

		results.push_back(make_pair(x4, y4));
	}

	for (vector<pair<int, int>>::iterator iter = results.begin(); iter < results.end(); ++iter) {
		cout << (*iter).first << " " << (*iter).second << endl;
	}

	return 0;
}