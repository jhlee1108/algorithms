#include <cstdio>
#include <cstring>

int N, M, check[1000][1000], p[10000001];
char map[1000][1000];

int find(int a) {
    if(p[a] < 0) return a;
    else p[a] = find(p[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    p[b] = a;
}

bool dfs(int n, int y, int x) {
    int ny, nx;
    check[y][x] = n;
    
    if(map[y][x] == 'N') {
        ny = y - 1;
        nx = x;
    }
    else if(map[y][x] == 'S') {
        ny = y + 1;
        nx = x;
    }
    else if(map[y][x] == 'W') {
        ny = y;
        nx = x - 1;
    }
    else {
        ny = y ;
        nx = x + 1;
    }

    if(!check[ny][nx]) return dfs(n, ny, nx);
    else if(check[ny][nx] == check[y][x]) return true;
    else {
        merge(check[y][x], check[ny][nx]);
        return false;
    }
}

int main() {
    scanf("%d %d\n", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%c\n", &map[i][j]);

    memset(p, -1, sizeof(p));
    int cnt = 1, ans = 0;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(!check[i][j] && dfs(cnt++, i, j)) ans++;

    printf("%d\n", ans);

    return 0;
}
