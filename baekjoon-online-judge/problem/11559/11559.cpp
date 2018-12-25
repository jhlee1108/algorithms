#include <cstdio>
#include <cstring>
#include <queue>

#define PII pair<int,int>

using namespace std;

char map[12][6];
int visited[12][6];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int y, int x) {
    int cnt = 0;
    char c = map[y][x];
    bool is_remove = false;
    vector<PII> v;
    queue<PII> q;
    q.push(make_pair(y, x));
    visited[y][x] = 1;

    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        cnt++;
        if(cnt == 4) is_remove = true;
        if(cnt <= 4) v.push_back(make_pair(y, x));
        else map[y][x] = '.';

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(0 <= ny && ny < 12 && 0 <= nx && nx < 6) {
                if(!visited[ny][nx] && map[ny][nx] == c) {
                    visited[ny][nx] = 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }

    if(is_remove) {
        for(int i=0; i<v.size(); i++)
            map[v[i].first][v[i].second] = '.';
        return 1;
    }

    return 0;
}

void move() {
    for(int i=11; i>=0; i--)
        for(int j=5; j>=0; j--)
            if(map[i][j] != '.') {
                int ny = i + 1;
                while(ny < 12 && map[ny][j] == '.') {
                    map[ny][j] = map[ny-1][j];
                    map[ny-1][j] = '.';
                    ny++;
                }
            }   
}

int go() {
    int ret = 0;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<12; i++)
        for(int j=0; j<6; j++)
            if(map[i][j] != '.' && bfs(i, j))
                ret = 1;

    return ret;
}

int main() {
    for(int i=0; i<12; i++)
        for(int j=0; j<6; j++)
            scanf("%c\n", &map[i][j]);

    int ans = 0;
    while(1) {
        int ret = go();
        if(ret == 0) break;
        ans += ret;
        move();
    }

    printf("%d\n", ans);

    return 0;
}
