#pragma warning(disable : 4996)

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<bool> visited;
vector<int> parents;
vector<vector<int>> tree;

void setParent(int parent, int child) {
	visited[child] = true;
	parents[child] = parent;

	for (int i = 0; i < tree[child].size(); ++i) {
		if(!visited[tree[child][i]])
			setParent(child, tree[child][i]);
	}
}

int main() {
	scanf("%d", &n);
	visited.resize(n + 1);
	parents.resize(n + 1);
	tree.resize(n + 1, vector<int>());
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	setParent(0, 1);
	for (int i = 2; i <= n; ++i) {
		printf("%d\n", parents[i]);
	}

	return 0;
}