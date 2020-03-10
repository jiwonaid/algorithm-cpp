#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> box;
queue<pair<int, int>> mq;

int r, c, day = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isIn(int x, int y) {
	if (x == -1 || x == r || y == -1 || y == c)
		return false;
	return true;
}

int BFS(int cnt) {
	day++;
	int qSize = mq.size();
	for(int i = 0; i < qSize; ++i) {
		pair<int, int> p = mq.front();
		mq.pop();
		int x2, y2;
		for (int k = 0; k < 4; ++k) {
			x2 = p.first + dx[k];
			y2 = p.second + dy[k];
			if (isIn(x2, y2)) {
				if (box[x2][y2] == 0) {
					box[x2][y2] = 1;
					cnt--;
					mq.push({ x2, y2 });
				}
			}
		}
	}

	return cnt;
}

int main() {
	int m, n, to = 0; scanf("%d %d", &m, &n);
	r = n;
	c = m;
	box.resize(r, vector<int>(c));
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			scanf("%d", &box[i][j]);
			if (box[i][j] == 1)
				mq.push({ i, j });
			if (box[i][j] == 0)
				to++;
		}
	}

	if (to) {
		while (to) {
			int temp = BFS(to);
			if (to == temp) {
				printf("-1");
				return 0;
			}
			else {
				to = temp;
			}
		}
	}
	printf("%d", day);
	
	return 0;
}