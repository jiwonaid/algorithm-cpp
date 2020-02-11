#include <iostream>
#include <string>

using namespace std;

int main() {
	string S;
	int arr[4];

	while (getline(cin, S) && !S.empty()) {
		fill(arr, arr + 4, 0);

		for (int i = 0; i < S.length(); ++i) {
			if (S[i] >= 'a' && S[i] <= 'z')
				arr[0]++;
			else if (S[i] >= 'A' && S[i] <= 'Z')
				arr[1]++;
			else if (S[i] >= '0' && S[i] <= '9')
				arr[2]++;
			else
				arr[3]++;
		}
		for (int i : arr)
			cout << i << ' ';
		cout << endl;
	}

	return 0;
}