#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

long long dp[201][201];

int main() {
    int N, K; scanf("%d %d", &N, &K);
    
    dp[0][0] = 1;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            for (int l = 0; l <= j; l++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % 1000000000;
            }
        }
    }

    printf("%d", dp[K][N]);

    return 0;
}