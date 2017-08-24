#include <cstdio>
#include <queue>

#define PII pair<int,int>

using namespace std;

int T, W, H;
char building[1000][1000];
int check[1000][1000];
int check_f[1000][1000];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<PII> q;
queue<PII> fq;

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d %d", &W, &H);
        while(!q.empty()) q.pop();
        while(!fq.empty()) fq.pop();

        for(int i=0; i<H; i++)
            for(int j=0; j<W; j++) {
                scanf("\n%c\n", &building[i][j]);
                check[i][j] = 0;
                check_f[i][j] = 0;
                if(building[i][j] == '@') {
                    q.push(make_pair(i, j));
                    check[i][j] = 1;
                }
                if(building[i][j] == '*') {
                    fq.push(make_pair(i, j));
                    check_f[i][j] = 1;
                }
            }

        bool is_impossible = true;
        int x, y;
        while(!(q.empty() && fq.empty())) {
            if(!q.empty()) {
                int q_size = q.size();
                for(int t=0; t<q_size; t++) {
                    y = q.front().first;
                    x = q.front().second;
                    q.pop();
                    if(building[y][x] == '*') continue;

                    if(x == 0 || x == W-1 || y == 0 || y == H-1) {
                        is_impossible = false;
                        break;
                    }


                    for(int i=0; i<4; i++) {
                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        if(0 <= nx && nx < W && 0 <= ny && ny < H) {
                            if(check[ny][nx] == 0 && building[ny][nx] == '.') {
                                q.push(make_pair(ny, nx));
                                check[ny][nx] = check[y][x] + 1;
                            }
                        }
                    }
                }
            }

            if(!is_impossible) break;

            if(!fq.empty()) {
                int fq_size = fq.size();
                for(int t=0; t<fq_size; t++) {
                    y = fq.front().first;
                    x = fq.front().second;
                    fq.pop();

                    for(int i=0; i<4; i++) {
                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        if(0 <= nx && nx < W && 0 <= ny && ny < H) {
                            if(check_f[ny][nx] == 0 && building[ny][nx] != '#') {
                                fq.push(make_pair(ny, nx));
                                building[ny][nx] = '*';
                                check_f[ny][nx] = 1;
                            }
                        }
                    }
                }
            }
        }

        if(is_impossible) printf("IMPOSSIBLE\n");
        else printf("%d\n", check[y][x]);
    }

    return 0;
}
