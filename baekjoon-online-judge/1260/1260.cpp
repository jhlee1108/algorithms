#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

bool check[1001];
vector<int> g[1001];

void dfs(int x) {
    check[x] = true;
    printf("%d ", x);

    for(int i=0; i<g[x].size(); i++) {
        int y = g[x][i];
        if(check[y] == false)
            dfs(y);
    }
}

void bfs(int x) {
    queue<int> q;
    q.push(x);
    check[x] = true;

    while(!q.empty()) {
        int y = q.front();
        q.pop();
        printf("%d ", y);
        for(int i=0; i<g[y].size(); i++) {
            int z = g[y][i];
            if(check[z] == false) {
                check[z] = true;
                q.push(z);
            }
        }
    }
}

int main() {
    int n, m, v, i, j;

    scanf("%d %d %d", &n, &m, &v);

    while(m--) {
        scanf("%d %d", &i, &j);
        g[i].push_back(j);
        g[j].push_back(i);
    }

    for(int k=1; k<=n; k++)
        sort(g[k].begin(), g[k].end());

    dfs(v);
    puts("");
    memset(check, false, sizeof(check));
    bfs(v);

    return 0;
}
