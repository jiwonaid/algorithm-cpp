#include <iostream>
#include <vector>
#include <algorithm> 
 
using namespace std;
 
vector<int> cache;
vector<int> answer;
 
void calc(int n, vector<int> f) {
	for (int i = 0; i < f.size(); ++i) {
		if (f[i] != 0) {
			cache[f[i] - 1] = 1;
			answer[i] = f[i];
		}
	}
 
	vector<int>::iterator it;
	for (int i = 0; i < answer.size(); ++i) {
		if (cache[i] == 0 && answer[i] == 0) {
			it = find(cache.begin(), cache.end(), 0);
			if (it == cache.end())
				return;
			else if(i == (it - cache.begin())) {
				it = find(it + 1, cache.end(), 0);
				answer[i] = (it - cache.begin() + 1);
				*it = 1;
			}
			else {
				answer[i] = (it - cache.begin() + 1);
				*it = 1;
			}
		}
	}
	for (int i = 0; i < answer.size(); ++i) {
		if (answer[i] == 0) {
			it = find(cache.begin(), cache.end(), 0);
			if (it == cache.end())
				return;
			else {
				answer[i] = (it - cache.begin() + 1);
				*it = 1;
			}
		}
	}
}
 
int main() {
	int n, input;
	vector<int> f;
 
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		f.push_back(input);
	}
	cache.assign(n, 0);
	answer.assign(n, 0);
	calc(n, f);
 
	for (vector<int>::const_iterator i = answer.begin(); i != answer.end(); ++i) {
		cout << *i << " ";
	}
 
	return 0;
}