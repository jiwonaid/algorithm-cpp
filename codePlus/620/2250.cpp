#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, pos = 1;
vector<int> node;
vector<int> low;
vector<int> high;
vector<pair<int, int>> tree;

void DFS(int idx, int level) {
	if (tree[idx].first != -1)
		DFS(tree[idx].first, level + 1);

	low[level] = min(low[level], pos);
	high[level] = max(high[level], pos);
	pos++;

	if (tree[idx].second != -1)
		DFS(tree[idx].second, level + 1);
}

int main() {
	scanf("%d", &n);
	node.resize(n + 1);
	low.resize(n + 1, 987654321);
	high.resize(n + 1);
	tree.resize(n + 1);
	int p, c1, c2;
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d %d", &p, &c1, &c2);
		node[p]++;
		tree[p].first = c1;
		if (c1 != -1)
			node[c1]++;
		tree[p].second = c2;
		if (c2 != -1)
			node[c2]++;
	}
	int root;
	for (int i = 1; i <= n; ++i)
		if (node[i] == 1)
			root = i;
	
	DFS(root, 1);
	int level = 1, width = 1;
	for (int i = 1; i <= n; ++i) {
		if (width < high[i] - low[i] + 1) {
			level = i;
			width = high[i] - low[i] + 1;
		}
	}
	printf("%d %d", level, width);

	return 0;
}