#include <cstdio>
#include <cstring>

int N, M, p[201];

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    p[x] = y;
}

int main() {
    memset(p, -1, sizeof(p));
    scanf("%d %d", &N, &M);
    
    int info;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            scanf("%d", &info);
            if(info) merge(i, j);
        }
    
    bool is_possible = true;
    int curr, next;
    scanf("%d", &curr);
    for(int i=1; i<M; i++) {
        scanf("%d", &next);
        if(find(curr) != find(next)) {
            is_possible = false;
            break;
        }
        curr = next;
    }

    puts(is_possible ? "YES" : "NO");

    return 0;
}
