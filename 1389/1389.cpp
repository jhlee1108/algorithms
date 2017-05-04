#include <cstdio>
#include <cstring>
#include <queue>

#define MIN(A,B) ((A) < (B) ? (A) : (B))

using namespace std;

int n, m;
int a[111][111];
int b[111];

int bfs(int x) {
    int sum = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(x,0));
    b[x] = 1;
    
    while(!q.empty()) {
        x = q.front().first;
        int l = q.front().second;
        q.pop();
        sum += l;

        for(int i=1; i<=n; i++) {
            if(a[x][i] == 1 && b[i] == 0) {
                q.push(make_pair(i,l+1));
                b[i] = 1;
            }
        }
    }

    return sum;
}

int main() {
    int ans;
    int min_value = 10000000;

    scanf("%d %d", &n, &m);

    while(m--) {
        int i, j;
        scanf("%d %d", &i, &j);
        a[i][j] = a[j][i] = 1;
    }

    for(int i=1; i<=n; i++) {
        memset(b, 0, sizeof(b));
        int r = bfs(i);
        if(min_value > r) {
            ans = i;
            min_value = r;
        }
    }

    printf("%d\n", ans);

    return 0;
}
