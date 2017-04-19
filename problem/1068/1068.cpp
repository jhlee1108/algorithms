#include <cstdio>

int g[50][50] = {0,};
int ans = 0;
int n;

void dfs(int x) {
    bool is_leaf = true;
    for(int i=0; i<n; i++) {
        if(g[x][i] == 1) {
            is_leaf = false;
            dfs(i);
        }
    }

    if(is_leaf)
        ans++;
}

int main() {
    int v, root;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &v);
        if(v == -1)
            root = i;
        else
            g[v][i] = 1;
    }

    scanf("%d", &v);

    if(v == root)
        printf("0");

    else {
        for(int i=0; i<n; i++)
            g[i][v] = 0;

        dfs(root);

        printf("%d", ans);
    }

    return 0;
}
