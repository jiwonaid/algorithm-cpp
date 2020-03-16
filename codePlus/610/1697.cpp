#pragma warning(disable : 4996)

#include <iostream>
#include <queue>

using namespace std;

int n, k;
int arr[100001];

int main() {
	scanf("%d %d", &n, &k);
	fill(arr, arr + 100001, 100001);
	queue<pair<int, int>> mq;
	mq.push({ n, 0 });

	while (!mq.empty()) {
		pair<int, int> p = mq.front();
		mq.pop();

		if (p.first >= 0 && p.first <= 100000 && p.second < arr[p.first]) {
			arr[p.first] = p.second;
			mq.push({ p.first - 1, p.second + 1 });
			mq.push({ p.first + 1, p.second + 1 });
			mq.push({ p.first * 2, p.second + 1 });
		}
	}
	printf("%d", arr[k]);

	return 0;
}