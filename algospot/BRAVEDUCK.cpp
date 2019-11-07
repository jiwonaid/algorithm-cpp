#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int here) {
	visited[here] = true;

	for (int i = 0; i < adj[here].size(); ++i) {
		bool isConnected = adj[here][i];
		if (isConnected && !visited[i]) {
			dfs(i);
		}
	}
}

bool isEscapable(vector<pair<int, int>> points, int N, int J) {
	int x1, y1, x2, y2;
	for (int i = 0; i < N + 2; ++i) {
		x1 = points[i].first;
		y1 = points[i].second;

		for (int j = 0; j < N + 2; ++j) {
			if(i == j)
				adj[i][j] = 1;
			else {
				x2 = points[j].first;
				y2 = points[j].second;

				if (sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) <= J)
					adj[i][j] = 1;
				else
					adj[i][j] = 0;
			}
		}
	}

	dfs(0);
	return visited[1];
}

int main() {
	vector<string> answers;
	int T, J;
	int x, y;
	int N;

	cin >> T;
	for (int i = 0; i < T; ++i) {
		vector<pair<int, int>> points;
		cin >> J;
		cin >> x >> y;
		points.push_back(make_pair(x, y));
		cin >> x >> y;
		points.push_back(make_pair(x, y));

		cin >> N;
		adj = vector<vector<int>>(N + 2, vector<int>(N + 2, 0));
		visited = vector<bool>(N + 2, false);
		
		for (int j = 0; j < N; ++j) {
			cin >> x >> y;
			points.push_back(make_pair(x, y));
		}

		string result = isEscapable(points, N, J) ? "YES" : "NO";
		answers.push_back(result);
	}

	for (vector<string>::const_iterator it = answers.begin(); it != answers.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}