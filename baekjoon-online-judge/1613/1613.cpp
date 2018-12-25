#include <cstdio>

int main() {
    int n, k, s, x, y;
    int a[401][401] = {0,};
    scanf("%d %d", &n, &k);
    
    while(k--) {
        scanf("%d %d", &x, &y);
        a[x][y] = -1;
        a[y][x] = 1;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            for(int k=1; k<=n; k++) {
                if(a[j][i] == -1 && a[i][k] == -1) {
                    a[j][k] = -1;
                    a[k][j] = 1;
                }
            }
        }
    }

    scanf("%d", &s);

    while(s--) {
        scanf("%d %d", &x, &y);
        printf("%d\n", a[x][y]);
    }

    return 0;
}
