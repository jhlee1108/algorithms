#include <cstdio>
#include <queue>
using namespace std;

struct point {
    int r, c, d, cnt;
    bool operator<(const point &p) const {
        return cnt > p.cnt;
    }
};

int M, N, map[100][100], check[100][100];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int end_r, end_c, end_d;

void bfs(int r, int c, int d, int cnt) {
    priority_queue<point> q;
    check[r][c] = cnt;
    point p;
    p.r = r; p.c = c; p.d = d; p.cnt = cnt;
    q.push(p);

    while(!q.empty()){
        r = q.top().r;
        c = q.top().c;
        d = q.top().d;
        cnt = q.top().cnt;
        q.pop();

        for(int i=0; i<4; i++) {
            int ncnt = cnt;
            int nd = (d + i) % 4;
            if(i != 0) ncnt++;
            if(d == 0 && nd == 1) ncnt++;
            if(d == 1 && nd == 0) ncnt++;
            if(d == 2 && nd == 3) ncnt++;
            if(d == 3 && nd == 2) ncnt++;
            if(r == end_r && c == end_c && nd == end_d) {
                check[r][c] = ncnt;
                return;
            }
            for(int j=1; j<=3; j++) {
                int nr = r + dy[nd] * j;
                int nc = c + dx[nd] * j;
                if(0 <= nr && nr < M && 0 <= nc && nc < N) {
                    if(map[nr][nc] == 1) break;
                    if(check[nr][nc] == -1) {
                        check[nr][nc] = ncnt+1;
                        p.r = nr; p.c = nc; p.d = nd; p.cnt = ncnt+1;
                        q.push(p);
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d %d", &M, &N);
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++) {
            scanf("%d", &map[i][j]);
            check[i][j] = -1;
        }

    int r, c, d;
    scanf("%d %d %d", &r, &c, &d);
    r--; c--; d--;
    scanf("%d %d %d", &end_r, &end_c, &end_d);
    end_r--; end_c--; end_d--;
    bfs(r, c, d, 0);

    printf("%d\n", check[end_r][end_c]);

    return 0;
}
