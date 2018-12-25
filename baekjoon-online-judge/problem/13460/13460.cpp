#include <cstdio>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, M;
char map[10][10];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int go(int ri, int rj, int bi, int bj, int cnt) {
    int ret = INF;
    if(cnt > 10) return ret;

    for(int i=0; i<4; i++) {
        bool is_success = false;
        bool is_fail = false;

        bool is_blue = false;
        int nri = ri;
        int nrj = rj;
        while(map[nri][nrj] != '#') {
            nri += dy[i];
            nrj += dx[i];
            if(map[nri][nrj] == 'B') is_blue = true;
            if(map[nri][nrj] == 'O') is_success = true;
        }
        nri -= dy[i];
        nrj -= dx[i];
        if(is_blue) {
            nri -= dy[i];
            nrj -= dx[i];
        }

        int nbi = bi;
        int nbj = bj;
        bool is_red = false;
        while(map[nbi][nbj] != '#') {
            nbi += dy[i];
            nbj += dx[i];
            if(map[nbi][nbj] == 'R') is_red = true;
            if(map[nbi][nbj] == 'O') is_fail = true;
        }
        nbi -= dy[i];
        nbj -= dx[i];
        if(is_red) {
            nbi -= dy[i];
            nbj -= dx[i];
        }

        if(is_fail) continue;
        if(is_success) {
            ret = min(ret, cnt);
            continue;
        }

        map[ri][rj] = '.';
        map[nri][nrj] = 'R';
        map[bi][bj] = '.';
        map[nbi][nbj] = 'B';
        ret = min(ret, go(nri, nrj, nbi, nbj, cnt+1));
        map[nri][nrj] = '.';
        map[ri][rj] = 'R';
        map[nbi][nbj] = '.';
        map[bi][bj] = 'B';
    }

    return ret;
}

int main() {
    int ri, rj, bi, bj;
    scanf("%d %d\n", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            scanf("%c\n", &map[i][j]);
            if(map[i][j] == 'R') {
                ri = i; rj = j;
            }
            if(map[i][j] == 'B') {
                bi = i; bj = j;
            }
        }

    int ans = go(ri, rj, bi, bj, 1);
    if(ans == INF) ans = -1;
    printf("%d\n", ans);

    return 0;
}
