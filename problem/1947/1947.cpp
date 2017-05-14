#include <cstdio>

#define MOD 1000000000

int main() {
    int n;
    long long a[1000001];

    scanf("%d", &n);

    a[1] = 0;
    a[2] = 1;

    for(int i=3; i<=n; i++) {
        a[i] = (i-1)*(a[i-1] + a[i-2]);
        a[i] %= MOD;
    }

    printf("%lld\n", a[n]);

    return 0;
}
