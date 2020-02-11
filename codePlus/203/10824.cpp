#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string A, B, C, D;

	cin >> A >> B >> C >> D;
	unsigned long long a = stoull(A + B, nullptr);
	unsigned long long b = stoull(C + D, nullptr);
	cout << a + b;

	return 0;
}