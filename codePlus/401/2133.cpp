#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

int dp[31];

int solve(int n) {
    if (n % 2 == 1)
        return 0;
    else if (n == 0)
        return 1;
    else if (n == 2)
        return 3;
    
    int& ret = dp[n];
    if (ret != -1)
        return ret;

    ret = solve(n - 2) * 3;
    for (int i = 0; i <= n - 4; i += 2)
        ret += solve(i) * 2;

    return ret;
}

int main() {
    int n; scanf("%d", &n);
    fill(dp, dp + 31, -1);
    
    printf("%d", solve(n));

    return 0;
}