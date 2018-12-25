#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

vector<int> g[20001];
int check[20001];

void dfs(int x, int n) {
    check[x] = n;

    for(int i=0; i<g[x].size(); i++) {
        int y = g[x][i];
        if(check[y] == 0)
            dfs(y, (n%2)+1);
        if(check[y] == check[x])
            check[y] = check[x] = 3;
    }
}

int main() {
    int k, v, e, i, j;

    scanf("%d", &k);

    while(k--) {
        scanf("%d %d", &v, &e);

        for(int a=1; a<=v; a++) {
            g[a].clear();
            check[a] = 0;
        }

        while(e--) {
            scanf("%d %d", &i, &j);
            g[i].push_back(j);
            g[j].push_back(i);
        }

        bool is_bipartite_graph = true;        
        for(int a=1; a<=v; a++)
            if(check[a] == 0)
                dfs(a, 1);

        for(int b=1; b<=v; b++) {
            if(check[b] == 3) {
                is_bipartite_graph = false;
                break;
            }
        }

        if(is_bipartite_graph)
            printf("YES\n");
        else
            printf("NO\n");

    }

    return 0;
}
