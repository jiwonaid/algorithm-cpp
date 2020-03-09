#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int here) {
	visited[here] = true;
	printf("%d ", here);
	for (int i = 0; i < adj[here].size(); ++i)
		if (!visited[adj[here][i]])
			dfs(adj[here][i]);
}

void bfs(int here) {
	queue<int> mq;

	visited[here] = true;
	printf("%d ", here);
	mq.push(here);
	
	while (!mq.empty()) {
		int idx = mq.front();
		mq.pop();

		for (int i = 0; i < adj[idx].size(); ++i) {
			if (!visited[adj[idx][i]]) {
				visited[adj[idx][i]] = true;
				printf("%d ", adj[idx][i]);
				mq.push(adj[idx][i]);
			}
		}
	}
}

int main() {
	int m, v, a, b; scanf("%d %d %d", &n, &m, &v);
	adj.resize(n + 1, vector<int>());
	visited.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(v);
	puts("");
	visited.assign(n + 1, false);
	bfs(v);

	return 0;
}