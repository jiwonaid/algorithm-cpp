#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int l, c; scanf("%d %d", &l, &c);
	vector<char> arr(c);
	for (int i = 0; i < c; ++i)
		scanf(" %c", &arr[i]);
	vector<bool> check(c);
	for (int i = 0; i < l; ++i)
		check[i] = true;

	sort(arr.begin(), arr.end());
	do {
		int countA = 0, countB = 0;
		string temp = "";
		for (int i = 0; i < c; ++i) {
			if (check[i]) {
				if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
					countA++;
				else
					countB++;
				temp += arr[i];
			}
		}
		if (countA > 0 && countB > 1)
			cout << temp << '\n';
	} while (prev_permutation(check.begin(), check.end()));

	return 0;
}