#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

bool arr[1000001];

void eratos(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (arr[i]) {
			for (int j = i * i; j <= n; j += i) {
				arr[j] = false;
			}
		}
	}
}

int main() {
	int T, N;

	fill(arr, arr + 1000001, true);
	// arr[0] = false;
	arr[1] = false;
	eratos(1000000);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		int temp = 0;
		for (int i = 2; i < N; ++i) {
			if (arr[i] && arr[N - i] && N - i >= i)
				temp++;
		}
		printf("%d\n", temp);
	}

	return 0;
}