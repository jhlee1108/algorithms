#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int d[111][111] = {0,};
    int c[111] = {0,};
    int n, k, a, b, x, y;

    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &k);

    while(k--) {
        scanf("%d %d", &x, &y);
        d[x][y] = d[y][x] = 1;
    }

    queue<pair<int,int>> q;
    q.push(make_pair(b,1));
    c[b] = 1;

    while(!q.empty()) {
        b = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for(int i=1; i<=n; i++) {
            if(d[b][i] == 1 && c[i] == 0) {
                q.push(make_pair(i,cnt+1));
                c[i] = cnt + 1;
            }
        }
    }
    
    printf("%d\n", c[a]-1);

    return 0;
}
