#include<iostream>

using namespace std;

typedef int KeyType;
// 트립의 한 노드를 저장한다
struct Node {
	// 노드에 저장된 원소
	KeyType key;
	// 이 노드의 우선순위 (priority)
	// 이 노드를 루트로 하는 서브트리의 크기 (size)
	int priority, size;
	// 두 노드의 자식 포인터
	Node* left, * right;
	// 생성자에서 난수 우선순위를 생성하고, size 와 left/right를 초기화한다
	Node(const KeyType& _key) : key(_key), priority(rand()),
		size(1), left(NULL), right(NULL) {
	}
	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRight(Node* newRight) { right = newRight; calcSize(); }
	// size 멤버를 갱신한다
	void calcSize() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
};

typedef pair<Node*, Node*> NodePair;
// root를 루트로 하는 트립을 key 미만의 값과 이상의 값을 갖는
// 두 개의 트립으로 분리한다.
NodePair split(Node* root, KeyType key) {
	if (root == NULL) return NodePair(NULL, NULL);
	// 루트가 key 미만이면 오른쪽 서브트리를 쪼갠다.
	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}
	// 루트가 key 이상이면 왼쪽 서브트리를 쪼갠다.
	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}
// root를 루트로 하는 트립에 새 노드 node를 삽입한 뒤 결과 트립의
// 루트를 반환한다.
Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;
	// node가 루트를 대체해야 한다. 해당 서브트리를 반으로 잘라
	// 각각 자손으로 한다.
	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}

// root를 루트로 하는 트리 중에서 k번째 원소를 반환한다.
Node* kth(Node* root, int k) {
	// 왼쪽 서브트리의 크기를 우선 계산한다.
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	if (k == leftSize + 1) return root;
	return kth(root->right, k - leftSize - 1);
}

int sumMedian(int N, int a, int b) {
	int ret = 0, arrA = 1983;
	Node* root = NULL;

	for (int i = 0; i < N; i++) {
		if (i != 0)
			arrA = (arrA * (long long)a + b) % 20090711;
		root = insert(root, new Node(arrA));

		int temp = kth(root, i / 2 + 1)->key;
		ret = (ret + temp) % 20090711;
	}

	return ret;
}

int main() {
	int C, N, a, b;

	cin >> C;
	for (int i = 0; i < C; ++i) {
		cin >> N >> a >> b;
		cout << sumMedian(N, a, b) << endl;
	}

	return 0;
}