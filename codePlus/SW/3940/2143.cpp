#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a, b;
vector<long long> arrA, arrB;

int main() {
	long long t; scanf("%lld", &t);
	int n, m;
	scanf("%d", &n);
	a.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	b.resize(m);
	for (int i = 0; i < m; ++i)
		scanf("%d", &b[i]);

	long long temp;
	for (int i = 0; i < n; ++i) {
		temp = a[i];
		arrA.push_back(temp);
		for (int j = i + 1; j < n; ++j) {
			temp += a[j];
			arrA.push_back(temp);
		}
	}
	for (int i = 0; i < m; ++i) {
		temp = b[i];
		arrB.push_back(temp);
		for (int j = i + 1; j < m; ++j) {
			temp += b[j];
			arrB.push_back(temp);
		}
	}
	sort(arrA.begin(), arrA.end());
	sort(arrB.begin(), arrB.end());

	/////

	long long result = 0;
	for (int i = 0; i < arrA.size(); ++i) {
		int low = lower_bound(arrB.begin(), arrB.end(), t - arrA[i]) - arrB.begin();
		int high = upper_bound(arrB.begin(), arrB.end(), t - arrA[i]) - arrB.begin();
		result += high - low;
	}
	printf("%lld", result);

	return 0;
}