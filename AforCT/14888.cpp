#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int N, maxV, minV;
vector<int> arr;
vector<int> oper;

void DFS(int plus, int minus, int mul, int div, int n, int temp) {
	if (n == N) {
		if (temp > maxV)
			maxV = temp;
		if (temp < minV)
			minV = temp;
	}
	if (plus > 0)
		DFS(plus - 1, minus, mul, div, n + 1, temp + arr[n]);
	if (minus > 0)
		DFS(plus, minus - 1, mul, div, n + 1, temp - arr[n]);
	if (mul > 0)
		DFS(plus, minus, mul - 1, div, n + 1, temp * arr[n]);
	if (div > 0)
		DFS(plus, minus, mul, div - 1, n + 1, temp / arr[n]);
}

int main() {
	scanf("%d", &N);
	arr = vector<int>(N);
	oper = vector<int>(4);

	for (int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	for (int i = 0; i < 4; ++i)
		scanf("%d", &oper[i]);
	maxV = numeric_limits<int>::min();
	minV = numeric_limits<int>::max();
	DFS(oper[0], oper[1], oper[2], oper[3], 1, arr[0]);

	printf("%d\n%d", maxV, minV);

	return 0;
}