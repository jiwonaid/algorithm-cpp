#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001][2];

int solve(vector<int>& arr) {
    int ret = arr[0];

    dp[0][0] = arr[0];
    dp[0][1] = 0;
    for (int i = 1; i < arr.size(); ++i) {
        dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        if (ret < dp[i][0])
            ret = dp[i][0];
        if (ret < dp[i][1])
            ret = dp[i][1];
    }

    return ret;
}

int main() {
    int n; scanf("%d", &n);
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    printf("%d", solve(arr));

    return 0;
}