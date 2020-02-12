#include <iostream>

using namespace std;

bool arr[1000001];

void eratos(int N) {
	for (int i = 2; i * i <= N; ++i) {
		if (arr[i] == true) {
			for (int j = i * i; j <= N; j += i) {
				arr[j] = false;
			}
		}
	}
}

void printPrime(int M, int N) {
	for (int i = M; i <= N; ++i) {
		if (arr[i])
			cout << i << '\n';
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); // cout << i << '\n';
	// scanf, printf
	int M, N;
	
	cin >> M >> N;
	fill_n(arr, 1000001, true);
	// arr[0] = false;
	arr[1] = false;

	eratos(N);
	printPrime(M, N);

	return 0;
}