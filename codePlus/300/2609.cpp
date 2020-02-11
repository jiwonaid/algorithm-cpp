#include <iostream>
#include <algorithm>

using namespace std;

int gCommon(int a, int b) {
	int ret = 1;
	for (int i = min(a, b); i >= 2; --i) {
        if (a % i == 0 && b % i == 0) {
            ret = i;
            break;
        }
    }

	return ret;
}

int lCommon(int a, int b) {
	int small = min(a, b);
	int big = max(a, b);
	
	for (int i = 1; i < 45000; ++i) {
		if ((i * small) % big == 0) {
			return i * small;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int a, b;
	
	cin >> a >> b;
	cout << gCommon(a, b) << endl;
	cout << lCommon(a, b) << endl;

	return 0;
}