#include <cstdio>
#include <cstring>
#include <queue>

#define PII pair<int,int>

using namespace std;

int N, M, map[100][100], dist[100][100];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct cmp {
    bool operator()(PII a, PII b) {
        return dist[a.first][a.second] > dist[b.first][b.second];
    }
};

priority_queue<PII, vector<PII>, cmp> pq;

int main() {
    scanf("%d %d", &M, &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%1d", &map[i][j]);
    
    memset(dist, -1, sizeof(dist));
    dist[0][0] = 0;
    pq.push(make_pair(0, 0));
    while(!pq.empty()) {
        int y = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(0 <= ny && ny < N && 0 <= nx && nx < M)
                if(dist[ny][nx] == -1) {
                    dist[ny][nx] = dist[y][x] + map[ny][nx];
                    pq.push(make_pair(ny, nx));
                }
        }
    }

    printf("%d\n", dist[N-1][M-1]);

    return 0;
}
