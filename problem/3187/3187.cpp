#include <cstdio>
#include <queue>

#define PII pair<int,int>

using namespace std;

int R, C, check[250][250];
char map[250][250];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int y, int x, int &sheep, int &wolf) {
    queue<PII> q;
    q.push(make_pair(y, x));
    check[y][x] = 1;
    sheep = 0;
    wolf = 0;
    bool is_outside = false;

    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        if(map[y][x] == 'v') wolf++;
        else if(map[y][x] == 'k') sheep++;

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(0 <= ny && ny < R && 0 <= nx && nx < C) {
                if(!check[ny][nx] && map[ny][nx] != '#') {
                    check[ny][nx] = 1;
                    q.push(make_pair(ny, nx));
                }
            }
            else is_outside = true;
        }
    }

    if(is_outside) {
        sheep = 0;
        wolf = 0;
    }
}

int main() {
    scanf("%d %d\n", &R, &C);

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            scanf("%c\n", &map[i][j]);
                
    int sheep = 0, wolf = 0;
    int sheep_ans = 0, wolf_ans = 0;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            if((map[i][j] == 'v' || map[i][j] == 'k') && !check[i][j]) {
                bfs(i, j, sheep, wolf);
                if(sheep > wolf) sheep_ans += sheep;
                else wolf_ans += wolf;
            }
                
    printf("%d %d\n", sheep_ans, wolf_ans);

    return 0;
}
