#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n, m, check[501];
vector<vector<int>> g(501);
queue<int> q;

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int level = 2;
    int ans = 0;
    q.push(1);
    check[1] = 1;
    while(level--) {
        int qsize = q.size();
        while(qsize--) {
            int x = q.front();
            q.pop();

            for(auto &y : g[x]) {
                if(!check[y]) {
                    q.push(y);
                    check[y] = 1;
                    ans++;
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
