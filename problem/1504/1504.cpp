#include <cstdio>
#include <vector>
#include <queue>
#include <limits.h>

#define MIN(A,B) (A < B ? A : B)

using namespace std;

int main() {
    int n, e; scanf("%d %d", &n, &e);
    vector<vector<pair<int,int>>> g(n+1);
    vector<vector<int>> dist(3, vector<int>(n+1, INT_MAX));
    
    for(int i=0; i<e; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }

    int a, b; scanf("%d %d", &a, &b);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int nodes[] = {1, a, b};
    
    for(int i=0; i<3; i++) {
    pq.push(make_pair(0, nodes[i]));
    dist[i][nodes[i]] = 0;

        while(!pq.empty()) {
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            for(auto &x : g[u]) {
                if(dist[i][x.first] > dist[i][u] + x.second) {
                    dist[i][x.first] = dist[i][u] + x.second;
                    pq.push(make_pair(dist[i][x.first], x.first));
                }
            }
        }
    }

    int ans, ans1, ans2;

    if(dist[0][a] == INT_MAX || dist[1][b] == INT_MAX || dist[2][n] == INT_MAX)
        ans1 = INT_MAX;
    else
        ans1 = dist[0][a] + dist[1][b] + dist[2][n];

    if(dist[0][b] == INT_MAX || dist[2][a] == INT_MAX || dist[1][n] == INT_MAX)
        ans2 = INT_MAX;
    else
        ans2 = dist[0][b] + dist[2][a] + dist[1][n];

    ans = MIN(ans1, ans2);
    if(ans == INT_MAX) printf("-1\n");
    else printf("%d\n", ans);

    return 0;
}
