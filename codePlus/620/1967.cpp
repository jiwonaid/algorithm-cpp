#pragma warning(disable : 4996)

#include <iostream>
#include <vector>

using namespace std;

int v, dia, farthest = -1;
vector<bool> visited;
vector<vector<pair<int, int>>> t;

void diameter(int pos, int cost) {
	visited[pos] = true;

	if (dia < cost) {
		dia = cost;
		farthest = pos;
	}
	for (int i = 0; i < t[pos].size(); ++i) {
		if (!visited[t[pos][i].first]) {
			diameter(t[pos][i].first, t[pos][i].second + cost);
		}
	}

	visited[pos] = false;
}

int main() {
	scanf("%d", &v);
	visited.resize(v + 1);
	t.resize(v + 1, vector<pair<int, int>>());

	int p, c, edge;
	for (int i = 0; i < v - 1; ++i) {
		scanf("%d %d %d", &p, &c, &edge);
		t[p].push_back({ c, edge });
		t[c].push_back({ p, edge });
	}

	diameter(1, 0);
	diameter(farthest, 0);
	printf("%d", dia);

	return 0;
}