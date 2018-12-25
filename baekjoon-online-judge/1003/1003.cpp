#include <cstdio>

int main() {
    int t, n;
    int count[2][41];

    scanf("%d", &t);

    count[0][0] = 1;
    count[1][0] = 0;
    count[0][1] = 0;
    count[1][1] = 1;
    for(int i=0; i<t; i++) {
        scanf("%d", &n);
        
        for(int j=2; j<=n; j++) {
            count[0][j] = count[0][j-1] + count[0][j-2];
            count[1][j] = count[1][j-1] + count[1][j-2];
        }

        printf("%d %d\n", count[0][n], count[1][n]);
    }

    return 0;
}
        
