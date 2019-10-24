#include <iostream>
#include <vector>

using namespace std;

int main() {
	int C;
	vector<unsigned int> numbers;
	vector<unsigned int> result;

	cin >> C;

	for (int i = 0; i < C; ++i) {
		unsigned int temp;
		cin >> temp;
		numbers.push_back(temp);
	}

	for (vector<unsigned int>::iterator iter = numbers.begin(); iter < numbers.end(); ++iter) {
		unsigned char temp1;
		unsigned char temp2;
		unsigned char temp3;
		unsigned char temp4;

		temp1 = *iter;
		temp2 = *iter >> 8;
		temp3 = *iter >> 16;
		temp4 = *iter >> 24;

		unsigned int add = 0;
		add += temp4;
		add += temp3 << 8;
		add += temp2 << 16;
		add += temp1 << 24;

		result.push_back(add);
	}

	for (vector<unsigned int>::iterator iter = result.begin(); iter < result.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}