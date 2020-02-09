#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int frq[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N, input;
	vector<int> arr;
	vector<int> ans;
	stack<int> st;

	cin >> N;
	ans.assign(N, -1);
	for (int i = 0; i < N; ++i) {
		cin >> input;
		arr.push_back(input);
		frq[input]++;
	}

	for (int i = 0; i < N; ++i) {
		while (!st.empty() && frq[arr[st.top()]] < frq[arr[i]]) {
			ans[st.top()] = arr[i];
			st.pop();
		}
		st.push(i);
	}

	for (auto it = ans.cbegin(); it != ans.cend(); ++it)
		cout << *it << ' ';

	return 0;
}