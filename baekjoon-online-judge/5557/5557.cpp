#include <cstdio>
#include <cstring>

int n;
int a[101];
long long  d[101][21];

long long go(int i, int j) {
    if(i < 0 || j < 0 || j > 20) return 0;
    if(i == 1 && j == a[1]) return 1;
    if(d[i][j] != -1LL) return d[i][j];

    d[i][j] = go(i-1, j-a[i]) + go(i-1, j+a[i]);

    return d[i][j];
}

int main() {
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    memset(d, -1LL, sizeof(d));

    long long ans = go(n-1, a[n]);

    printf("%lld", ans);

    return 0;
}
