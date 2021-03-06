#include <vector>

using namespace std;

// vector<list<int>> adj;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int here) {
	visited[here] = true;

	for (int i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!visited[there])
			dfs(there);
	}
}

void dfsAll() {
	visited = vector<bool>(adj.size(), false);

	for (int i = 0; i < adj.size(); ++i) {
		if(!visited[i])
			dfs(i);
	}
}