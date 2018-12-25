#include <cstdio>
#include <queue>
#include <tuple>

#define MAX(A,B) ((A) > (B) ? (A) : (B))

using namespace std;

int m, n, h;
int box[111][111][111];
int d[111][111][111];
int dx[6] = {-1,1,0,0,0,0};
int dy[6] = {0,0,-1,1,0,0};
int dz[6] = {0,0,0,0,-1,1};

int main() {
    queue<tuple<int,int,int>> q;
    scanf("%d %d %d", &m, &n, &h);

    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                scanf("%d", &box[i][j][k]);
                if(box[i][j][k] == -1)
                    d[i][j][k] = -1;
                else if(box[i][j][k] == 1) {
                    q.push(make_tuple(i,j,k));
                    d[i][j][k] = 1;
                }
            }
        }
    }

    while(!q.empty()) {
        int z = get<0>(q.front());
        int x = get<1>(q.front());
        int y = get<2>(q.front());
        q.pop();

        for(int i=0; i<6; i++) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 <= nz && nz < h && 0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(d[nz][nx][ny] == -1)
                    continue;
                else if(d[nz][nx][ny] == 0) {
                    q.push(make_tuple(nz,nx,ny));
                    d[nz][nx][ny] = d[z][x][y] + 1;
                }
            }
        }
    }

    int ans = 1;
    for(int i=0; i<h; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<m; k++) {
                if(d[i][j][k] == 0) {
                    ans = 0;
                    goto END;
                }
                else
                    ans = MAX(ans,d[i][j][k]);
            }
        }
    }

END:
    printf("%d\n", ans-1);

    return 0;
}
