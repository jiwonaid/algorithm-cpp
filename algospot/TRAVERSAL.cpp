#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostorder(const vector<int>& preorder, const vector<int>& inorder) {
	int N = preorder.size();
	if (N == 0)
		return;

	int root = preorder[0];
	int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	int R = N - L - 1;
	printPostorder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostorder(slice(preorder, L + 1, N), slice(inorder, L + 1, N));
	cout << root << ' ';
}

int main() {
	int C, N, input;
	
	cin >> C;
	for (int i = 0; i < C; ++i) {
		vector<int> preorder, inorder;
		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> input;
			preorder.push_back(input);
		}
		for (int j = 0; j < N; ++j) {
			cin >> input;
			inorder.push_back(input);
		}
		printPostorder(preorder, inorder);
		cout << endl;
	}

	return 0;
}