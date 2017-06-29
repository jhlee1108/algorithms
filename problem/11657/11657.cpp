#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>

#define PII pair<int,int>

using namespace std;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<vector<PII>> g(n+1);
    vector<int> dist(n+1, INT_MAX);

    for(int i=0; i<m; i++) {
        int x, y, w; scanf("%d %d %d", &x, &y, &w);
        g[x].push_back(make_pair(w, y));
    }

    bool minus_cycle = false;
    dist[1] = 0;

    for(int i=0; i<n; i++) {
        for(int j=1; j<=n; j++) {
            for(auto &x : g[j]) {
                if(dist[j] != INT_MAX && dist[x.second] > dist[j] + x.first) {
                    dist[x.second] = dist[j] + x.first;
                    if(i == n-1) minus_cycle = true;
                }
            }
        }
    }

    if(minus_cycle) printf("-1\n");
    else {
        for(int i=2; i<=n; i++) {
            if(dist[i] == INT_MAX) printf("-1\n");
            else printf("%d\n", dist[i]);
        }
    }

    return 0;
}
