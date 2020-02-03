#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> order;

void makeMatrix(const vector<string>& dict) {
	adj.assign(26, vector<int>(26, 0));
	for (int i = 0; i < dict.size() - 1; ++i) {
		int j = i + 1;
		int len = min(dict[i].size(), dict[j].size());

		for (int k = 0; k < len; ++k) {
			if (dict[i][k] != dict[j][k]) {
				adj[dict[i][k] - 'a'][dict[j][k] - 'a'] = 1;
				break;
			}
		}
	}
}

void dfs(int here) {
	visited[here] = true;

	for (int i = 0; i < adj.size(); ++i) {
		if (adj[here][i] && !visited[i])
			dfs(i);
	}
	order.push_back(here);
}

void topoloSort() {
	visited.assign(26, false);
	order.clear();
	for (int i = 0; i < 26; ++i) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	reverse(order.begin(), order.end());
	for (int i = 0; i < 26; ++i) {
		for (int j = i + 1; j < 26; ++j)
			if (adj[order[j]][order[i]])
				order.clear();
	}
}

int main() {
	int C, N;
	string input;
	
	cin >> C;
	for (int i = 0; i < C; ++i) {
		vector<string> dict;

		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> input;
			dict.push_back(input);
		}
		makeMatrix(dict);
		topoloSort();
		if (order.empty())
			cout << "INVALID HYPOTHESIS" << endl;
		else {
			for (auto it = order.begin(); it != order.end(); ++it) {
				cout << (char)(*it + 'a');
			}
			cout << endl;
		}
	}

	return 0;
}