#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int upperD[100001];
int lowerD[100001];

int solve(const vector<int>& first, const vector<int>& second) {
    int n = first.size();
    for (int i = 1; i < n; ++i) {
        upperD[i] = max(upperD[i - 1], lowerD[i - 1] + first[i]);
        lowerD[i] = max(lowerD[i - 1], upperD[i - 1] + second[i]);
    }

    return max(upperD[n - 1], lowerD[n - 1]);
}

int main() {
    int t, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        vector<int> upperP(n);
        vector<int> lowerP(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &upperP[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &lowerP[i]);
        }
        upperD[0] = upperP[0];
        lowerD[0] = lowerP[0];

        printf("%d\n", solve(upperP, lowerP));
    }

    return 0;
}