#include <iostream>
#include <map>

using namespace std;

map<int, int> coords;

bool isDominated(int p, int q) {
	map<int, int>::const_iterator it = coords.lower_bound(p);
	
	if (it == coords.end())
		return false;

	return q < it->second;
}

void removeDominated(int p, int q) {
	map<int, int>::iterator it = coords.lower_bound(p);
	
	if (it == coords.begin()) return;
	--it;

	while (true) {
		if (it->second > q)
			break;

		if (it == coords.begin()) {
			coords.erase(it);
			break;
		}
		else {
			map<int, int>::iterator jt = it;
			--jt;
			coords.erase(it);
			it = jt;
		}
	}
}

int main() {
	int C, N, p, q;
	
	cin >> C;
	for (int i = 0; i < C; ++i) {
		int ret = 0;
		coords.clear();
		
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> p >> q;
			if (!isDominated(p, q)) {
				removeDominated(p, q);
				coords.insert(make_pair(p, q));
			}
			ret += coords.size();
		}
		cout << ret << endl;
	}

	return 0;
}