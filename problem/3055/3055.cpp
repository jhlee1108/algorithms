#include <cstdio>
#include <queue>

#define PII pair<int,int>

using namespace std;

int R, C;
char map[50][50];
int check[50][50];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<PII> q;
queue<PII> wq;

int main() {
    scanf("%d %d", &R, &C);

    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) {
            scanf("\n%c\n", &map[i][j]);
            if(map[i][j] == 'S') {
                q.push(make_pair(i, j));
                check[i][j] = 1;
            }
            if(map[i][j] == '*') {
                wq.push(make_pair(i, j));
                check[i][j] = 1;
            }
        }

    bool is_kaktus = true;
    int x, y;
    while(!(q.empty() && wq.empty())) {
        if(!wq.empty()) {
            int wq_size = wq.size();
            for(int t=0; t<wq_size; t++) {
                y = wq.front().first;
                x = wq.front().second;
                wq.pop();

                for(int i=0; i<4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if(0 <= ny && ny < R && 0 <= nx && nx < C) {
                        if(check[ny][nx] == 0 && map[ny][nx] == '.') {
                            wq.push(make_pair(ny, nx));
                            check[ny][nx] = 1;
                            map[ny][nx] = '*';
                        }
                    }
                }
            }
        }

        if(!q.empty()) {
            int q_size = q.size();
            for(int t=0; t<q_size; t++) {
                y = q.front().first;
                x = q.front().second;
                q.pop();

                if(map[y][x] == 'D') {
                    is_kaktus = false;
                    break;
                }

                for(int i=0; i<4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if(0 <= ny && ny < R && 0 <= nx && nx < C) {
                        if(check[ny][nx] == 0 && (map[ny][nx] == '.' || map[ny][nx] == 'D')) {
                            q.push(make_pair(ny, nx));
                            check[ny][nx] = check[y][x] + 1;
                        }
                    }
                }
            }
        }

        if(!is_kaktus) break;
    }

    if(is_kaktus) printf("KAKTUS\n");
    else printf("%d\n", check[y][x]-1);

    return 0;
}
