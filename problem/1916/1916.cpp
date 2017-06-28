#include <cstdio>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<vector<pair<int,int>>> g(n+1);
    vector<int> dist(n+1, INT_MAX);

    for(int i=0; i<m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back(make_pair(v,w));
    }

    int start, end; scanf("%d %d", &start, &end);

    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        for(auto &x : g[u]) {
            if(dist[x.first] > dist[u] + x.second) {
                dist[x.first] = dist[u] + x.second;
                pq.push(make_pair(x.second, x.first));
            }
        }
    }

    printf("%d\n", dist[end]);

    return 0;
}
