#include <vector>

using namespace std;

int C, N, x[100], y[100], r[100];

bool isChild(int parent, int child);

struct TreeNode {
	// string label;
	// TreeNode* parent;
	vector<TreeNode*> children;
};

TreeNode* getTree(int root) {
	TreeNode* ret = new TreeNode();
	
	for (int ch = 0; ch < N; ++ch) {
		if (isChild(root, ch))
			ret->children.push_back(getTree(ch));
	}

	return ret;
}

bool isEnclosed(int a, int b) {
	// return
}

bool isChild(int parent, int child) {
	if(!isEnclosed(parent, child))
		return false;

	for (int i = 0; i < N; ++i)
		if (i != parent && i != child && isEnclosed(parent, i) && isEnclosed(i, child))
			return false;

	return true;
}