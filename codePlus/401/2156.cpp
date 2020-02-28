#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[10001];

int solve(const vector<int>& amount) {
    dp[0] = amount[0];
    dp[1] = amount[0] + amount[1];
    dp[2] = max(dp[1], amount[0] + amount[2]);
    dp[2] = max(dp[2], amount[1] + amount[2]);

    for (int i = 3; i < amount.size(); ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + amount[i]);
        dp[i] = max(dp[i], dp[i - 3] + amount[i] + amount[i - 1]);
    }

    return dp[amount.size() - 1];
}

int main() {
    int n; scanf("%d", &n);
    vector<int> amount(n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &amount[i]);
    }

    printf("%d", solve(amount));

    return 0;
}