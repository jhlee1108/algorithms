#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, paper[500][500];

int dx[19][4] = {{0, 1, 2, 3},
                {0, 0, 0, 0},
                {0, 1, 0, 1},
                {0, 0, 0, 1},
                {0, 1, 2, 2},
                {0, 1, 1, 1},
                {0, 1, 2, 0},
                {0, 1, 1, 1},
                {0, 1, 2, 2},
                {0, 0, 0, 1},
                {0, 0, 1, 2},
                {0, 0, 1, 1},
                {0, 1, 1, 2},
                {0, 0, 1, 1},
                {0, 1, 1, 2},
                {0, 1, 2, 1},
                {0, 0, 0, 1},
                {0, 1, 2, 1},
                {0, 1, 1, 1}};

int dy[19][4] = {{0, 0, 0, 0},
                {0, 1, 2, 3},
                {0, 0, 1, 1},
                {0, 1, 2, 2},
                {0, 0, 0, -1},
                {0, 0, 1, 2},
                {0, 0, 0, 1},
                {0, 0, -1, -2},
                {0, 0, 0, 1},
                {0, 1, 2, 0},
                {0, 1, 1, 1},
                {0, 1, 1, 2},
                {0, 0, -1, -1},
                {0, -1, -1, -2},
                {0, 0, 1, 1},
                {0, 0, 0, 1},
                {0, 1, 2, 1},
                {0, 0, 0, -1},
                {0, -1, 0, 1}};

int max_sum(int y, int x) {
    int ret = 0;
    int ps;

    for(int i=0; i<19; i++) {
        ps = 0;
        for(int j=0; j<4; j++) {
            int ny = y + dy[i][j];
            int nx = x + dx[i][j];

            if(0 <= ny && ny < N && 0 <= nx && nx < M) {
                ps += paper[ny][nx];
            }
            else {
                ps = 0;
                break;
            }
        }
        ret = max(ret, ps);
    }

    return ret;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d", &paper[i][j]);
    
    int ans = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            ans = max(ans, max_sum(i, j));

    printf("%d\n", ans);

    return 0;
}
