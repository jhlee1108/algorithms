#include <cstdio>
#include <vector>

using namespace std;

vector<int> g[1001];
bool check[1001];

void dfs(int x) {
    check[x] = true;

    for(int y : g[x])
        if(!check[y]) dfs(y);
}

int main() {
    int t, n, a;

    scanf("%d", &t);

    while(t--) {
        int ans = 0;

        scanf("%d", &n);

        for(int i=1; i<=n; i++) {
            check[i] = false;
            g[i].clear();
            scanf("%d", &a);
            g[i].push_back(a);
        }

        for(int i=1; i<=n; i++) {
            if(check[i] == 0) {
                dfs(i);
                ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
