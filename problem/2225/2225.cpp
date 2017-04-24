#include <cstdio>

int main() {
    int n, k;
    int d[201][201] = {0,};

    scanf("%d %d", &n, &k);

    d[0][0] = 1;
    for(int i=1; i<=k; i++)
        for(int j=0; j<=n; j++)
            for(int k=0; k<=j; k++)
                d[i][j] = (d[i][j] + d[i-1][j-k]) % 1000000000;

    printf("%d\n", d[k][n]);

    return 0;
}
