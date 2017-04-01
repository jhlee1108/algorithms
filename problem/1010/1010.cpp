#include <cstdio>

int main() {
    int t, n, m;
    int count[30][30];

    for(int i=1; i<30; i++) {
        for(int j=1; j<=i; j++) {
            if(j == 1)
                count[i][j] = i;
            else if(i == j)
                count[i][j] = 1;
            else
                count[i][j] = count[i-1][j-1] + count[i-1][j];
        }
    }

    scanf("%d", &t);

    for(int i=0; i<t; i++) {
        scanf("%d %d", &n, &m);
        printf("%d\n", count[m][n]);
    }

    return 0;
}

