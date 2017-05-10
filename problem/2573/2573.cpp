#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int a[333][333];
int b[333][333];
int c[333][333];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void remove(int (*p)[333], int (*q)[333]) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(p[i][j] > 0){
                int t = 0;
                for(int k=0; k<4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                        if(p[nx][ny] <= 0)
                            t++;
                    }
                }
                q[i][j] = p[i][j] - t;
                if(q[i][j] < 0)
                    q[i][j] = 0;
            }
            else
                q[i][j] = 0;
        }
    }
}

void bfs(int x, int y, int (*p)[333]) {
   queue<pair<int,int>> q;
   q.push(make_pair(x,y));
   c[x][y] = 1;

   while(!q.empty()) {
       x = q.front().first;
       y = q.front().second;
       q.pop();

       for(int i=0; i<4; i++) {
           int nx = x + dx[i];
           int ny = y + dy[i];

           if(0 <= nx && nx < n && 0 <= ny && ny < m) {
               if(p[nx][ny] > 0 && c[nx][ny] == 0) {
                   q.push(make_pair(nx,ny));
                   c[nx][ny] = 1;
               }
           }
       }
   }
}

int main() {
    int ans = -1;
    int s = 0;
    int flag = 0;

    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%d", &a[i][j]);

    while(s < 2) {
        memset(c, 0, sizeof(c));
        s = 0;
        
        if(flag == 0) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(a[i][j] > 0 && c[i][j] == 0) {
                        bfs(i, j, a);
                        s++;
                    }
                }
            }
            remove(a,b);
            flag = 1;
        }

        else {
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    if(b[i][j] > 0 && c[i][j] == 0) {
                        bfs(i, j, b);
                        s++;
                    }
                }
            }
            remove(b,a);
            flag = 0;
        }

        if(s == 0) {
            ans = 0;
            break;
        }

        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
