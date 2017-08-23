#include <cstdio>

int N, G[100][100], ans[100][100];

void dfs(int u, int v) {
    for(int i=0; i<N; i++) {
        if(ans[v][i] == 1) {
            ans[u][i] = 1;
            continue;
        }
        if(ans[u][i] == 0 && G[v][i] == 1) {
            ans[u][i] = 1;
            dfs(u, i);
        }
    }
}

int main() {
    scanf("%d", &N);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &G[i][j]);

    for(int i=0; i<N; i++)
        dfs(i, i);

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }

    return 0;
}
