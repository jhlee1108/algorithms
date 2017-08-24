#include <cstdio>
#include <queue>

using namespace std;

struct Point {
    int x, y, z;
};

int L, R, C;
char building[30][30][30];
int check[30][30][30];
int minutes[30][30][30];
int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {-1, 1, 0, 0, 0, 0};

int main() {
    while(1) {
        scanf("%d %d %d", &L, &R, &C);

        if(L == 0 && R == 0 && C == 0) break;

        int x, y, z;
        for(int i=0; i<L; i++) {
            for(int j=0; j<R; j++) {
                for(int k=0; k<C; k++) {
                    scanf("\n%c\n", &building[i][j][k]);
                    if(building[i][j][k] == 'S') {
                        x = i; y = j; z = k;
                    }
                    check[i][j][k] = 0;
                    minutes[i][j][k] = 0;
                }
            }
        }

        bool is_trap = true;
        queue<Point> q;
        Point p;
        p.x = x; p.y = y; p.z = z;
        q.push(p);
        check[x][y][z] = 1;

        while(!q.empty()) {
            x = q.front().x;
            y = q.front().y;
            z = q.front().z;
            q.pop();

            if(building[x][y][z] == 'E') {
                is_trap = false;
                break;
            }

            for(int i=0; i<6; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];

                if(0 <= nx && nx < L && 0 <= ny && ny < R && 0 <= nz && nz < C) {
                    if(building[nx][ny][nz] != '#' && check[nx][ny][nz] == 0) {
                        Point np;
                        np.x = nx; np.y = ny; np.z = nz;
                        q.push(np);
                        check[nx][ny][nz] = 1;
                        minutes[nx][ny][nz] = minutes[x][y][z] + 1;
                    }
                }
            }
        }

        if(is_trap) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", minutes[x][y][z]);
    }

    return 0;
}
