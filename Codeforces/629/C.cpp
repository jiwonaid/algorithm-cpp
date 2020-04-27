#pragma warning(disable : 4996)

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n; scanf("%d", &t);
	vector<int> arr, a, b;

	while (t--) {
		scanf("%d", &n);
		arr.assign(n, 0);
		a.assign(n, 0);
		b.assign(n, 0);
		for (int i = 0; i < n; ++i) {
			scanf("%1d", &arr[i]);
		}

		bool check = true;
		for (int i = 0; i < n; ++i) {
			if (check) {
				if (arr[i] == 1) {
					check = false;
					a[i] = 1;
				}
				else if (arr[i] == 2) {
					a[i] = 1;
					b[i] = 1;
				}
			}
			else {
				b[i] = arr[i];
			}
		}
		for (int i = 0; i < n; ++i)
			printf("%d", a[i]);
		puts("");
		for (int i = 0; i < n; ++i)
			printf("%d", b[i]);
		puts("");
	}

	return 0;
}