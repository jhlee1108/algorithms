#include <cstdio>
#include <algorithm>
#include <queue>

#define PII pair<int,int>

using namespace std;

int N, M, map[8][8];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs() {
    int tmap[8][8];
    queue<PII> q;
    int ret = 0;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            tmap[i][j] = map[i][j];
            if(tmap[i][j] == 2)
                q.push(make_pair(i, j));
        }

    while(!q.empty()) {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        ret++;

        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < M && 0 <= ny && ny < N) {
                if(tmap[ny][nx] == 0) {
                    tmap[ny][nx] = 2;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
    
    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    int wall = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1) wall++;
        }

    int ans = 1e9;
    for(int a=0; a<N; a++) 
        for(int b=0; b<M; b++) {
            if(map[a][b] != 0) continue;
            map[a][b] = 1;
            for(int c=0; c<N; c++)
                for(int d=0; d<M; d++) {
                    if(map[c][d] != 0) continue;
                    map[c][d] = 1;
                    for(int e=0; e<N; e++)
                        for(int f=0; f<M; f++) {
                            if(map[e][f] != 0) continue;
                            map[e][f] = 1;
                            ans = min(ans, bfs());
                            map[e][f] = 0;
                        }
                    map[c][d] = 0;
                }
            map[a][b] = 0;
        }

    printf("%d\n", N*M-3-wall-ans);

    return 0;
}
