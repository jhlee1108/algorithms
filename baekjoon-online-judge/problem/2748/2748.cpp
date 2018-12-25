#include <cstdio>

int main() {
    int n;
    long long a[91];

    scanf("%d", &n);

    a[0] = 0;
    a[1] = 1;

    for(int i=2; i<=n; i++)
        a[i] = a[i-1] + a[i-2];

    printf("%lld", a[n]);

    return 0;
}
