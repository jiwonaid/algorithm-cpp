#pragma warning(disable : 4996)

#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin >> t;

	while (t--) {
		int n, a, b; cin >> n >> a >> b;
		string result;
		for (int i = 0; i < b; ++i)
			result += i + 'a';
		for (int i = 0; i < a - b; ++i)
			result += result[i];
		for (int i = 0; i < n - a; ++i)
			result += result[i];

		cout << result << '\n';
	}

	return 0;
}