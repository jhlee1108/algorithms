#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, height[5001], cnt[5001];
vector<vector<int>> g(5001);

int dfs(int n) {
    int ret = 1;

    if(cnt[n] != 0) return cnt[n];

    for(auto &x : g[n])
        if(height[x] > height[n]) ret = max(ret, dfs(x)+1);

    return cnt[n] = ret;
}

int main() {
    scanf("%d %d", &N, &M);

    int start = 1;
    for(int i=1; i<=N; i++) {
        scanf("%d", &height[i]);
        if(height[start] > height[i]) start = i;
    }

    for(int i=1; i<=M; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(start);

    for(int i=1; i<=N; i++)
        printf("%d\n", dfs(i));

    return 0;
}
