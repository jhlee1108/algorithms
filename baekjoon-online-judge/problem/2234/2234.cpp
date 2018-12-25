#include <cstdio>
#include <algorithm>
#include <queue>

#define PII pair<int,int>
#define isin(N, M, n, m) (0 <= N && N < n && 0 <= M && M < m)

using namespace std;

int n, m, map[50][50], check[50][50], size[2501];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int find_max_two_room_size() {
    int ret = 0;
    
    for(int y=0; y<m; y++)
        for(int x=0; x<n; x++)
            for(int i=0; i<4; i++) {
                int t = 1 << i;
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(isin(nx, ny, n, m) && (map[y][x] & t) && check[y][x] != check[ny][nx])
                    ret = max(ret, size[check[y][x]] + size[check[ny][nx]]);
            }

    return ret;
}

int bfs(int y, int x, int num) {
    queue<PII> q;
    q.push(make_pair(y, x));
    check[y][x] = num;
    int cnt = 1;

    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int t = 1 << i;
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(isin(nx, ny, n ,m) && !(check[ny][nx] || (map[y][x] & t))) {
                q.push(make_pair(ny, nx));
                check[ny][nx] = num;
                cnt++;
            }
        }
    }
    
    return size[num] = cnt;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &map[i][j]);

    int num_of_room = 0, max_one_room_size = 0;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(!check[i][j]) max_one_room_size = max(max_one_room_size, bfs(i, j, ++num_of_room));

    printf("%d\n%d\n%d\n", num_of_room, max_one_room_size, find_max_two_room_size());

    return 0;
}
