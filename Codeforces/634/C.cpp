#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t; scanf("%d", &t);

	while (t--) {
		int n; scanf("%d", &n);
		vector<int> arr(n);
		vector<int> skills(n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			skills[arr[i] - 1]++;
		}

		if (n < 2)
			printf("%d\n", 0);
		else {
			sort(arr.begin(), arr.end(), greater<>());
			arr.erase(unique(arr.begin(), arr.end()), arr.end());

			sort(skills.begin(), skills.end(), greater<>());

			if (skills[0] < arr.size())
				printf("%d\n", skills[0]);
			else if (skills[0] == arr.size())
				printf("%d\n", skills[0] - 1);
			else
				printf("%d\n", arr.size());
		}
	}

	return 0;
}