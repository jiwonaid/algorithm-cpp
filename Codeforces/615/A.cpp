#include <iostream>

using namespace std;

int main() {
	int t, a, b, c, n, sum, amount;

	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> n;
		sum = a + b + c + n;
		amount = sum / 3;
		if (sum % 3 == 0 && amount >= a && amount >= b && amount >= c && n == (3 * amount) - a - b - c) {
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;
	}

	return 0;
}