#pragma warning(disable : 4996)

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

void minusTN(int n) {
	if (n == 0)
		return;

	if (n % 2 == 0) {
		v.push_back(0);
		minusTN(-(n / 2));
	}
	else {
		v.push_back(1);
		if (n > 0) 
			minusTN(-(n / 2));
		else
			minusTN((-n + 1) / 2);
	}
}

int main() {
	int N;

	scanf("%d", &N);
	if(N == 0)
		printf("%d", 0);
	else {
		minusTN(N);
		for (auto it = v.crbegin(); it != v.crend(); ++it)
			printf("%d", *it);
	}

	return 0;
}