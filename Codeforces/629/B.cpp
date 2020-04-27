#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

int main() {
	int t, n, k; scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &n, &k);

		int cnt = 1;
		int number = 2;
		int first = n - 2;
		while (cnt < k) {
			cnt += number;
			number++;
			first--;
		}

		for (int i = 0; i < first; ++i)
			printf("a");
		printf("b");
		for (int i = 0; i < cnt - k; ++i)
			printf("a");
		printf("b");
		for (int i = 0; i < n - first - (cnt - k) - 2; ++i)
			printf("a");
		puts("");
	}

	return 0;
}