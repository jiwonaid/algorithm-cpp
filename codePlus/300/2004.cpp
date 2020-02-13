#pragma warning(disable : 4996)

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<long long, long long> fac(long long n) {
    long long two = 0, five = 0;

    for (long long i = 2; i <= n; i *= 2) {
        two += n / i;
    }

    for (long long i = 5; i <= n; i *= 5) {
        five += n / i;
    }
    
    return make_pair(two, five);
}

int main() {
    long long n, m;
    pair<long long, long long> p1, p2, p3;

    scanf("%lld %lld", &n, &m);
    p1 = fac(n);
    p2 = fac(m);
    p3 = fac(n - m);

    printf("%d", min(p1.first - p2.first - p3.first, p1.second - p2.second - p3.second));

    return 0;
}