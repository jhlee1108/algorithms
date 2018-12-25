#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N, check[100001];
vector<vector<int>> g(100001);
queue<int> q;

int main() {
    scanf("%d", &N);
    for(int i=0; i<N-1; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    q.push(1);
    check[1] = 1;
    while(!q.empty()) {
        int root = q.front();
        q.pop();

        for(int child : g[root]) {
            if(!check[child]) {
                q.push(child);
                check[child] = root;
            }
        }
    }

    for(int i=2; i<=N; i++)
        printf("%d\n", check[i]);
    
    return 0;
}
