#include <iostream>

using namespace std;

bool arr[1000001];

void eratos(int N) {
	for (int i = 2; i * i <= N; ++i) {
		if (arr[i] == true) {
			for (int j = i * i; j <= N; j += i) {
				arr[j] = false;
			}
		}
	}
}

void guess(int input) {
	for (int i = input - 1; i > 2; i -= 2) {
		if (arr[i]) {
			for (int j = 3; j <= i; j += 2) {
				if (arr[j]) {
					if (j + i > input)
						break;
					else if (j + i == input) {
						printf("%d = %d + %d\n", input, j, i);
						return;
					}
				}
			}
		}
	}
	printf("Goldbach's conjecture is wrong.\n");
}

int main() {
	int input;

	fill(arr, arr + 1000001, true);
	// arr[0] = false;
	arr[1] = false;
	eratos(1000000);

	while (scanf("%d", &input) == 1) {
		if (input == 0)
			break;
		guess(input);
	}

	return 0;
}