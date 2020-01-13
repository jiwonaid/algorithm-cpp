#include <iostream>
#include <vector>
 
using namespace std;
 
int calc(int n, int k) {
	int ret = 0;
	int temp = n - ret;
 
	ret = (n / k) * k;
	if (temp == 0)
		return ret;
	else if ((k / 2) > temp)
		ret += temp;
	else
		ret += k / 2;
 
	return ret;
}
 
int main() {
	int t, n, k;
	vector<int> answers;
 
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n >> k;
		answers.push_back(calc(n, k));
	}
 
	for (vector<int>::const_iterator i = answers.begin(); i != answers.end(); ++i) {
		cout << *i << endl;
	}
 
	return 0;
}