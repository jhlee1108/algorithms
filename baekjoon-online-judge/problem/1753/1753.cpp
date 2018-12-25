#include <cstdio>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

int main() {
    int v, e, k;

    scanf("%d %d", &v, &e);
    scanf("%d", &k);

    vector<vector<pair<int,int>>> g(v+1);
    vector<int> d(v+1, INT_MAX);
    d[k] = 0;

    for(int i=0; i<e; i++) {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        g[x].push_back(make_pair(y,w));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(k,0));

    while(!pq.empty()) {
        int u = pq.top().first;
        int w = pq.top().second;
        pq.pop();

        for(auto &x : g[u]) {
            if(d[x.first] > (w + x.second)) {
                d[x.first] = w + x.second;
                pq.push(make_pair(x.first, d[x.first]));
            }
        }
    }

    for(int i=1; i<=v; i++) {
        if(d[i] == INT_MAX)
            printf("INF\n");
        else
            printf("%d\n", d[i]);
    }

    return 0;
}
