#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

int main() {
	int t, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		if (a == b)
			printf("0\n");
		else {
			if ((a % 2) == (b % 2)) {
				if (a > b)
					printf("1\n");
				else
					printf("2\n");
			}
			else {
				if (a > b)
					printf("2\n");
				else
					printf("1\n");
			}
		}
	}

	return 0;
}