#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

int main() {
	int t, a, b, cnt; scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &a, &b);
		cnt = 0;
		if (a % b != 0) {
			int temp = (a / b) * b + b;
			cnt = temp - a;
		}
		printf("%d\n", cnt);
	}

	return 0;
}