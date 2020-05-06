#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {
	int n, s; scanf("%d %d", &n, &s);
	arr.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	int l = 0, r = 0, sum = 0, len = 100001;
	while (r < n) {
		sum += arr[r];
		r++;
		if(sum >= s) {
			while (l < r && sum - arr[l] >= s) {
				sum -= arr[l];
				l++;
			}
			len = min(len, r - l);
		}
	}

	len == 100001 ? printf("%d", 0) : printf("%d", len);

	return 0;
}