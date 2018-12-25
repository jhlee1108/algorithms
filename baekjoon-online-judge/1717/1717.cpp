#include <cstdio>
#include <cstring>

int n, m;
int p[1000001];

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
    memset(p, -1, sizeof(p));
    scanf("%d %d", &n, &m);
    
    int cmd, a, b;
    while(m--) {
        scanf("%d %d %d", &cmd, &a, &b);
        if(cmd == 0) merge(a, b);
        else puts(find(a) == find(b) ? "YES" : "NO");
    }

    return 0;
}
