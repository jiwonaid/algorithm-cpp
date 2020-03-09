#pragma warning(disable : 4996)

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;

bool countDfs(int here, int count) {
	if (count == 4)
		return true;
	else {
		visited[here] = true;
		for (int i = 0; i < adj[here].size(); ++i) {
			if (!visited[adj[here][i]]) {
				if (countDfs(adj[here][i], count + 1))
					return true;
			}
		}
		visited[here] = false;
	}

	return false;
}

int main() {
	int m, a, b; scanf("%d %d", &n, &m);
	adj.resize(n, vector<int>());
	visited.resize(n);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		if (countDfs(i, 0)) {
			printf("1");
			return 0;
		}
	}
	printf("0");

	return 0;
}