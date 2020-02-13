#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcGDC(vector<int> pair) {
    int ret = 1, a = pair[0], b = pair[1];

    for (int i = min(a, b); i >= 2; --i) {
        if (a % i == 0 && b % i == 0) {
            ret = i;
            break;
        }
    }

    return ret;
}

long long combination(vector<int> v) {
    long long ret = 0;
    vector<int> pair;
    vector<bool> com(v.size());

    fill(com.begin(), com.begin() + 2, true);
    do {
        pair.clear();
        for (int i = 0; i < v.size(); ++i) {
            if (com[i]) {
                pair.push_back(v[i]);
                if (pair.size() == 2)
                    break;
            }
        }
        ret += calcGDC(pair);
    } while (prev_permutation(com.begin(), com.end()));

    return ret;
}

int main() {
    int t, n, input;

    scanf("%d", &t);
    while (t--) {
        vector<int> v;

        scanf("%d", &n);
        while (n--) {
            scanf("%d", &input);
            v.push_back(input);
        }
        printf("%lld\n", combination(v));
    }

    return 0;
}