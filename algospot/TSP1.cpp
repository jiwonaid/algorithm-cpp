#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

double calDist(const vector<vector<double>> distance, int path[], int N) {
	double ret = 8.0 * 1415;
	double tLength;

	do {
		tLength = 0.0;
		for (int i = 0; i < N - 1; ++i) {
			tLength += distance[path[i]][path[i + 1]];
		}
		ret = min(ret, tLength);
	} while (std::next_permutation(path, path + N));
	
	return ret;
}

int main() {
	vector<double> answers;
	int C;
	int N;

	cin >> C;
	for (int i = 0; i < C; ++i) {
		vector<vector<double>> distance;
		vector<double> row;
		double temp;
		
		cin >> N;
		int* path = new int[N];

		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				cin >> temp;
				row.push_back(temp);
			}
			distance.push_back(row);
			row.clear();
			path[j] = j;
		}

		double result = calDist(distance, path, N);
		delete[] path;

		answers.push_back(result);
	}

	for (vector<double>::const_iterator i = answers.begin(); i < answers.end(); ++i) {
		printf("%.10f \n", *i);
	}

	return 0;
}