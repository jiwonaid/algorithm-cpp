#pragma warning(disable : 4996)

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    int temp = n, cnt = 0, result = 0;
    while (temp / 10 != 0) {
        temp /= 10;
        cnt++;
    }
    for (int i = 0; i < cnt; ++i) {
        result += 9 * pow(10, i) * (i + 1);
    }
    result += (n - pow(10, cnt) + 1) * (cnt + 1);

    printf("%d", result);

    return 0;
}