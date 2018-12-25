#include <cstdio>

#define ll long long

int n;
ll a[200001], b, max_a, min_a, left, right;

int main() {
    scanf("%d", &n);
    max_a = 1e18;
    min_a = 0;
    for (int i = 1; i <= n / 2; i++) {
        scanf("%lld", &b);
        left = min_a;
        right = b - min_a;
        if (max_a < b - min_a) {
            min_a = b - max_a;
        } else {
            max_a = b - min_a;
        }
        a[n - i + 1] = max_a;
        a[i] = min_a;
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", a[i]);
    }
    return 0;
}