#include <cstdio>

int main() {
    int n, m, k, i, j, x, y;
    int matrix[301][301];
    int sum[301][301];

    scanf("%d %d", &n, &m);

    for(int a=1; a<=n; a++) {
        for(int b=1; b<=m; b++) {
            scanf("%d", &matrix[a][b]);
        }
    }

    scanf("%d", &k);

    for(int a=0; a<k; a++) {
        scanf("%d %d %d %d", &i, &j, &x, &y);

        for(int b=i; b<=x; b++) {
            for(int c=j; c<=y; c++) {
                if(b == i && c == j)
                    sum[b][c] = matrix[b][c];
                else if(b == i)
                    sum[b][c] = sum[b][c-1] + matrix[b][c];
                else if(c == j)
                    sum[b][c] = sum[b-1][c] + matrix[b][c];
                else
                    sum[b][c] = sum[b-1][c] + sum[b][c-1] - sum[b-1][c-1]
                                + matrix[b][c];
            }
        }

        printf("%d\n", sum[x][y]);
    }

    return 0;
}
