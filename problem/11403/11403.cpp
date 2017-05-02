#include <cstdio>
#include <queue>

using namespace std;

int m[101][101];
int ans[101][101];
int n;

void bfs(int x) {
    int check[101] = {0,};
    queue<int> q;
    q.push(x);

    while(!q.empty()) {
        int a = q.front();
        q.pop();

        for(int i=0; i<n; i++) {
            if(m[a][i] == 1) {
                ans[x][i] = 1;
                if(check[i] == 0)
                    q.push(i);
            }
        }
        check[a] = 1;
    }
}

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &m[i][j]);

    for(int i=0; i<n; i++)
        bfs(i);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }

    return 0;
}
