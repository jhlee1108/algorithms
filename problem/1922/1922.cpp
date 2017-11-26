#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

struct edge {
    int a, b, c;
    edge(int a, int b, int c) : a(a), b(b), c(c) {}
    bool operator<(const edge &e) const {
        return e.c < c;
    }
};


int N, M, p[1001];
priority_queue<edge> pq;

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return false;
    p[x] = y;
    return true;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; i++) {
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        pq.push(edge(a, b, c));
    }

    memset(p, -1, sizeof(p));
    int ans = 0;
    while(!pq.empty()) {
        edge e = pq.top();
        pq.pop();
        if(merge(e.a, e.b)) ans += e.c;
    }

    printf("%d\n", ans);

    return 0;
}
