#include <cstdio>

int n, k, a[101], d[10001];

int main() {
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);

    d[0] = 1;
    for(int i=1; i<=n; i++)
        for(int j=a[i]; j<=k; j++)
            d[j] += d[j - a[i]];

    printf("%d\n", d[k]);

    return 0;
}
