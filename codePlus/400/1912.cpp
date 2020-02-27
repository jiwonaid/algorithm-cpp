#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

int main() {
	int n, input, maxSum = -100000001, pSum = 0;

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &input);
		pSum += input;
		if (maxSum < pSum)
			maxSum = pSum;
		if (pSum < 0)
			pSum = 0;
	}

	printf("%d", maxSum);

	return 0;
}