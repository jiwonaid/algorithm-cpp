#include <iostream>
#include <queue>
#include <string>

using namespace std;

string solve(int N, int K) {
	string ret = "";
	queue<int> q;

	for (int i = 1; i <= N; ++i)
		q.push(i);

	while (!q.empty()) {
		for (int i = 0; i < K - 1; ++i) {
			q.push(q.front());
			q.pop();
		}
		ret += to_string(q.front()) + ", ";
		q.pop();
	}
	return ret.erase(ret.size()-2, 2);
}

int main() {
	int N, K;

	cin >> N >> K;
	cout << '<' << solve(N, K) << '>';

	return 0;
}