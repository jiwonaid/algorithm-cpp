#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string solve(int N);
bool isAbundant(int& N, vector<int>& v);
bool isSemiperfect(int& N, vector<int>& v);

int main() {
	string answers;
	int C;
	cin >> C;

	for (int i = 0; i < C; ++i) {
		int N;
		cin >> N;

		answers += solve(N) + "\n";
	}

	cout << answers;

	return 0;
}

string solve(int N) {
	vector<int> divisors;
	divisors.push_back(1);

	int j = N / 2;
	for (int i = 2; i < j; ++i) {
		if (N % i == 0) {
			divisors.push_back(i);
			j = N / i;
			divisors.push_back(j);
		}
	}

	if (isAbundant(N, divisors) && !isSemiperfect(N, divisors))
		return "weird";
	else
		return "not weird";
}

bool isAbundant(int& N, vector<int>& v) {
	int sum = 0;
	for (vector<int>::const_iterator iter = v.begin(); iter < v.end(); ++iter) {
		sum += *iter;
	}

	if (sum > N)
		return true;
	else
		return false;
}

/* Some are originated from https://www.geeksforgeeks.org/semiperfect-number/ */
bool isSemiperfect(int& N, vector<int>& v) {
	sort(v.begin(), v.end());

	int n = N;
	int r = v.size();

	bool** subset = new bool*[r + 1];
	for (int i = 0; i < (r + 1); ++i) {
		subset[i] = new bool[(n + 1)];
	}

	// initialize 1st column to true 
	for (int i = 0; i <= r; ++i)
		subset[i][0] = true;

	// initialize 1st row to false (except the zero position) 
	for (int i = 1; i <= n; ++i)
		subset[0][i] = false;

	// loop to find whther the number is semiperfect 
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (j < v[i - 1])
				subset[i][j] = subset[i - 1][j];
			else {
				subset[i][j] = subset[i - 1][j] ||
					subset[i - 1][j - v[i - 1]];
			}
		}
	}

	bool result = subset[r][n];
	for (int i = 0; i < (r + 1); ++i) {
		delete[] subset[i];
	}
	delete[] subset;

	return result;
}