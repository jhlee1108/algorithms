#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define PII pair<int,int>

int R, C, group[1500][1500], d[1500][1500];
char map[1500][1500];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<PII> q;
vector<int> p;

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    p[x] = y;
}

void make_group(int y, int x, int cnt) {
    queue<PII> nq;
    nq.push(make_pair(y, x));
    group[y][x] = cnt;
    p.push_back(-1);

    while(!nq.empty()) {
        y = nq.front().first;
        x = nq.front().second;
        nq.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(0 <= ny && ny < R && 0 <= nx && nx < C)
                if(map[ny][nx] != 'X' && !group[ny][nx]) {
                    group[ny][nx] = cnt;
                    nq.push(make_pair(ny, nx));
                }
        }
    }
}

int main() {
    int y1 = -1, x1 = -1, y2 = -1, x2 = -1;
    
    scanf("%d %d\n", &R, &C);
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) {
            scanf("%c\n", &map[i][j]);
            if(map[i][j] == '.') q.push(make_pair(i ,j));
            if(map[i][j] == 'L') {
                if(y1 == -1) {
                    y1 = i; x1 = j;
                }
                else {
                    y2 = i; x2 = j;
                }
                q.push(make_pair(i, j));
            }
        }

    int cnt = 1;
    p.push_back(0);
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            if(map[i][j] != 'X' && !group[i][j])
                make_group(i, j, cnt++);

    int g1 = group[y1][x1];
    int g2 = group[y2][x2];
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(0 <= ny && ny < R && 0 <= nx && nx < C) {
                if(d[ny][nx] == 0 && group[ny][nx] == 0) {
                    group[ny][nx] = group[y][x];
                    d[ny][nx] = d[y][x] + 1;
                    q.push(make_pair(ny, nx));
                }
                if(group[ny][nx] != 0 && group[ny][nx] != group[y][x]) {
                    merge(group[ny][nx], group[y][x]);
                    if(find(g1) == find(g2)) {
                        printf("%d\n", d[ny][nx]);
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
