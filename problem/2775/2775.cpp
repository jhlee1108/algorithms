#include <cstdio>

int main() {
    int t, k, n;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &k);
        scanf("%d", &n);
        int a[15][15] = {0,};

        for(int i=0; i<15; i++)
            a[0][i] = i;
        
        for(int i=1; i<=k; i++)
            for(int j=1; j<=n; j++)
                for(int k=1; k<=j; k++)
                    a[i][j] += a[i-1][k];

        printf("%d\n", a[k][n]);
    }

    return 0;
}
