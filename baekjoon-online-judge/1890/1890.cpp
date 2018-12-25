#include <cstdio>

int n;
long long a[101][101];
long long dp[101][101];

int main() {
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%lld", &a[i][j]);

    dp[1][1] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(a[i][j] == 0) continue;
            if(i + a[i][j] <= n)
                dp[i+a[i][j]][j] += dp[i][j];
            if(j + a[i][j] <= n)
                dp[i][j+a[i][j]] += dp[i][j];
        }
    }

    printf("%lld\n", dp[n][n]);

    return 0;
}
