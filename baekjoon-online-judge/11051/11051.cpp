#include <cstdio>

int main() {
    int n, k; scanf("%d %d", &n, &k);
    int a[1001][1001] = {0,};
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=i; j++) {
            if(j == 0) a[i][j] = 1;
            else if(i == j) a[i][j] = 1;
            else a[i][j] = (a[i-1][j-1] + a[i-1][j]) % 10007;
        }
    }

    printf("%d\n", a[n][k]);

    return 0;
}
