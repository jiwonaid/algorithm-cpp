#include <iostream> 

using namespace std;

int a, b, c;

void factorization(int n) {
	a = 1, b = 1, c = 1;
	int count = 0;

	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0 && count == 0) {
			count++;
			n /= i;
			a = i;
		}
		else if (n % i == 0 && count == 1) {
			n /= i;
			b = i;
			c = n;
			return;
		}
	}
}

int main() {
	int t, n;

	cin >> t;
	while (t--) {
		cin >> n;
		factorization(n);
		if (b != 1 && b != c) {
			cout << "YES" << endl;
			cout << a << ' ' << b << ' ' << c << endl;
		}
		else
			cout << "NO" << endl;
	}

	return 0;
}

/*
void printNumbers() {
	int a, b, c = 1;
	int n = pFactor.size();

	if (n == 3) {
		if (pFactor[0] != pFactor[1] && pFactor[1] != pFactor[2]) {
			cout << "YES" << endl;
			cout << pFactor[0] << ' ' << pFactor[1] << ' ' << pFactor[2] << endl;
			return;
		}
	}
	else if (n > 3) {
		if (pFactor[0] != pFactor[1]) {
			a = pFactor[0];
			b = pFactor[1];
			for (int i = 2; i < n; ++i) {
				c *= pFactor[i];
			}
		}
		else {
			a = pFactor[0];
			b = pFactor[1] * pFactor[2];
			for (int i = 3; i < n; ++i) {
				c *= pFactor[i];
			}
		}
		if (a != c && b != c) {
			cout << "YES" << endl;
			cout << a << ' ' << b << ' ' << c << endl;
			return;
		}
	}

	cout << "NO" << endl;
}
*/