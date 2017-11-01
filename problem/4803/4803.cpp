#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> g(501);
queue<int> q;
int p[501], check[501];

int find(int x) {
    if(p[x] == -1) return x;
    return p[x] = find(p[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return false;
    p[y] = x;
    return true;
}

int main() {
    int t = 1;
    while(true) {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;

        memset(p, -1, sizeof(p));
        memset(check, 0, sizeof(check));
        for(int i=1; i<=n; i++)
            g[i].clear();

        for(int i=0; i<m; i++) {
            int u, v; scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(check[i] == 0) {
                q.push(i);
                bool is_tree = true;
                while(!q.empty()) {
                    int root = q.front();
                    q.pop();
                    check[root] = 1;

                    for(int x : g[root]) {
                        if(!check[x]) {
                            if(merge(root, x)) q.push(x);
                            else is_tree = false;
                        }
                    }
                }
                if(is_tree) ans++;
            }
        }

        printf("Case %d: ", t);
        if(ans == 0) puts("No trees.");
        else if(ans == 1) puts("There is one tree.");
        else printf("A forest of %d trees.\n", ans);
        t++;
    }

    return 0;
}
