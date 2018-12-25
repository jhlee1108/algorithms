#include <cstdio>

int main() {
    int n, m, k, i, j, x, y;
    int matrix[301][301];
    int psum[301][301];

    scanf("%d %d", &n, &m);

    for(int a=1; a<=n; a++) {
        int ps = 0;
        for(int b=1; b<=m; b++) {
            scanf("%d", &matrix[a][b]);
            ps += matrix[a][b];
            psum[a][b] = ps;
        }
    }

    scanf("%d", &k);

    while(k--) {
        scanf("%d %d %d %d", &i, &j, &x, &y);
        int ans = 0;

        for(int a=i; a<=x; a++)
            ans += (psum[a][y] - psum[a][j-1]);

        printf("%d\n", ans);
    }

    return 0;
}
