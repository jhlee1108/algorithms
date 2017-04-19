#include <cstdio>

using namespace std;

int g[100001];
int d[100001];
int s[100001];

int dfs(int x, int &step, int cnt) {
    if(d[x] != 0) {
        if(step != s[x])
            return 0;
        return cnt - d[x];
    }

    d[x] = cnt;
    s[x] = step;
    return dfs(g[x], step, cnt+1);
}

int main() {
    int t, n;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for(int i=1; i<=n; i++) {
            scanf("%d", &g[i]);
            d[i] = 0;
            s[i] = 0;
        }
        
        int ans = 0;
        for(int i=1; i<=n; i++)
            if(d[i] == 0)
                ans += dfs(i, i, 1);
        
        printf("%d\n", n-ans);
        
    }

    return 0;
}
