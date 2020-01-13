#include <iostream>
#include <vector>
 
using namespace std;
 
int calc(int h, int m) {
	int ret = 0;
 
	ret += (23 - h) * 60;
	ret += 60 - m;
 
	return ret;
}
 
int main() {
	int t, h, m;
	vector<int> answers;
 
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> h >> m;
		answers.push_back(calc(h, m));
	}
 
	for (vector<int>::const_iterator i = answers.begin(); i != answers.end(); ++i) {
		cout << *i << endl;
	}
 
	return 0;
}