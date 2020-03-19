#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

int n;
char tree[26][2];

void preorder(int pos) {
	if (pos == n)
		return;
	
	printf("%c", pos + 'A');
	if (tree[pos][0] != '.')
		preorder(tree[pos][0] - 'A');
	if (tree[pos][1] != '.')
		preorder(tree[pos][1] - 'A');
}

void inorder(int pos) {
	if (pos == n)
		return;

	if (tree[pos][0] != '.')
		inorder(tree[pos][0] - 'A');
	printf("%c", pos + 'A');
	if (tree[pos][1] != '.')
		inorder(tree[pos][1] - 'A');
}

void postorder(int pos) {
	if (pos == n)
		return;

	if (tree[pos][0] != '.')
		postorder(tree[pos][0] - 'A');
	if (tree[pos][1] != '.')
		postorder(tree[pos][1] - 'A');
	printf("%c", pos + 'A');

}
int main() {
	scanf("%d", &n);
	char parent;
	for (int i = 0; i < n; ++i) {
		scanf(" %c", &parent);
		for (int j = 0; j < 2; ++j) {
			scanf(" %c", &tree[parent - 'A'][j]);
		}
	}

	preorder(0);
	puts("");
	inorder(0);
	puts("");
	postorder(0);

	return 0;
}