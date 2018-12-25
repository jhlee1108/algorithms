#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, univ[1001];

struct Edge {
    int d, u, v;
    bool operator<(const Edge &e) const {
        return d > e.d;
    }
};

int find(int a) {
    if(univ[a] < 0) return a;
    return univ[a] = find(univ[a]);
}

bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    univ[a] = b;
    return true;
}

int main() {
    scanf("%d %d\n", &N, &M);

    for(int i=1; i<=N; i++) {
        char c; scanf("%c ", &c);
        univ[i] = c;
    }

    priority_queue<Edge> pq;
    for(int i=1; i<=M; i++) {
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        if(univ[u] != univ[v]) {
            Edge e;
            e.d = d; e.u = u; e.v = v;
            pq.push(e);
        }
    }

    fill(univ, univ+N+1, -1);
    int cnt = 1;
    int ans = 0;
    while (!pq.empty() && cnt < N) {
        Edge e = pq.top();
        pq.pop();

        if(merge(e.u, e.v)) {
            ans += e.d;
            cnt++;
        }
    }

    bool is_connect = true; cnt = 0;
    for(int i=1; i<=N; i++) {
        if(univ[i] < 0) cnt++;
        if(cnt >= 2) {
            is_connect = false;
            break;
        }
    }

    if(!is_connect) ans = -1;
    printf("%d\n", ans);

    return 0;
}
