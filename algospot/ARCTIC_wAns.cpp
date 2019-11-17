#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

double distance(const pair<double, double> p1, const pair<double, double> p2) {
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int dfs(int here) {
	visited[here] = true;
	int ret = 1;

	for (int i = 0; i < adj[here].size(); ++i) {
		bool isConnected = adj[here][i];
		if (isConnected && !visited[i]) {
			ret += dfs(i);
		}
	}
	return ret;
}

double calcOutput(int N, const vector<pair<double, double>> points) {
	double ret = 0.0;
	vector<vector<double>> disArr = vector<vector<double>>(N, vector<double>(N, 0.0));
	vector<double> distV;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j)
				continue;
			else {
				disArr[i][j] = distance(points[i], points[j]);
				if (i < j)
					distV.push_back(disArr[i][j]);
			}
		}
	}
	sort(distV.begin(), distV.end());

	for (int i = 0; i < N; ++i) {
		if (distV.empty())
			break;
		double temp = distV[i];
		visited = vector<bool>(N, false);

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j || disArr[i][j] <= temp) {
					adj[i][j] = 1;
				}
				else
					adj[i][j] = 0;
			}
		}

		if (dfs(0) == N) {
			ret = temp;
			break;
		}
	}

	return ret;
}

int main() {
	vector<double> answers;
	int C, N;
	double x, y;

	cin >> C;
	if (C < 1 || C > 50)
		exit(-1);

	for (int i = 0; i < C; ++i) {
		cin >> N;
		if (N < 1 || N > 100)
			exit(-1);

		vector<pair<double, double>> points;
		adj = vector<vector<int>>(N, vector<int>(N, 0));
		for (int j = 0; j < N; ++j) {
			cin >> x >> y;
			points.push_back(make_pair(x, y));
		}
		answers.push_back(calcOutput(N, points));
	}

	for (int i = 0; i < answers.size(); ++i) {
		cout << fixed << setprecision(2);
		cout << answers[i] << endl;
	}

	return 0;
}