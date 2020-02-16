#pragma warning(disable : 4996)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	int N, S, inputA, ans;
	vector<int> v;

	scanf("%d %d", &N, &S);
	while (N--) {
		scanf("%d", &inputA);
		v.push_back(abs(inputA - S));
	}

	ans = v[0];
	for (auto it = v.cbegin() + 1; it != v.cend(); ++it) {
		ans = gcd(ans, *it);
	}
	printf("%d", ans);

	return 0;
}