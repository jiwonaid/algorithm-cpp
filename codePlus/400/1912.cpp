#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

int main() {
	int n, input;
	int maxSum = 0, pSum = 0, maxValue = -1001;

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &input);
		
		if (maxValue < input)
			maxValue = input;
		pSum += input;
		if (pSum < 0)
			pSum = 0;
		if (maxSum < pSum)
			maxSum = pSum;
	}

	if (maxSum == 0)
		printf("%d", maxValue);
	else
		printf("%d", maxSum);

	return 0;
}