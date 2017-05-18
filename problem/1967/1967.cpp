#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>> a[10001];
int d[10001];
int n, m;
int ans = 0;

void bfs(int x) {
    queue<int> q;
    q.push(x);
    d[x] = 0;

    while(!q.empty()) {
        x = q.front();
        q.pop();

        for(int i=0; i<a[x].size(); i++) {
            int v = a[x][i].first;
            int c = a[x][i].second;
            if(d[v] == -1) {
                d[v] = d[x] + c;
                if(ans < d[v]) {
                    ans = d[v];
                    m = v;
                }
                q.push(v);
            }
        }
    }
}

int main() {
    int x, y, z;
    scanf("%d", &n);

    while(scanf("%d %d %d\n", &x, &y, &z) == 3) {
        a[x].push_back(make_pair(y,z));
        a[y].push_back(make_pair(x,z));
    }

    memset(d, -1, sizeof(d));
    bfs(1);
    memset(d, -1, sizeof(d));
    bfs(m);
    
    printf("%d\n", ans);

    return 0;
}
