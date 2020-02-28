#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

int dp[100001];

int solve(int n) {
    dp[0] = 1;
    dp[1] = 3;
    for (int i = 2; i <= n; ++i)
        dp[i] = (2 * dp[i - 1] + dp[i - 2]) % 9901;

    return dp[n];
}

int main() {
    int N;
    scanf("%d", &N);

    printf("%d", solve(N));

    return 0;
}