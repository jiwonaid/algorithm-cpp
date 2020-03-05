#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr;
vector<int> temp;
set<vector<int>> ans;

void solve(int trial) {
    if (trial == 0) {
        ans.insert(temp);
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (temp.empty() || temp.back() <= arr[i]) {
                temp.push_back(arr[i]);
                solve(trial - 1);
                temp.pop_back();
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    arr.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());

    solve(m);

    for (auto v : ans) {
        for (int it : v)
            printf("%d ", it);
        printf("\n");
    }

    return 0;
}