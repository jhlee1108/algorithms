#include <cstdio>

int N, M, r, c, d, map[50][50];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    scanf("%d %d %d %d %d", &N, &M, &r, &c, &d);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d", &map[i][j]);

    int ans = 0;
    int step = 1;
    int cnt = 0;
    while(1) {
        if(step == 1) {
            map[r][c] = 2;
            ans++;
            step = 2;
        }
        else {
            int nd = (d + 3) % 4;
            int nr = r + dy[nd];
            int nc = c + dx[nd];
            if(map[nr][nc] == 0) {
                r = nr;
                c = nc;
                d = nd;
                step = 1;
                cnt = 0;
            }
            else {
                d = nd;
                cnt++;

                if(cnt == 4) {
                    nr = r - dy[d];
                    nc = c - dx[d];
                    if(map[nr][nc] == 1) break;
                    r = nr;
                    c = nc;
                    cnt = 0;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
