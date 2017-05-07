#include <cstdio>
#include <queue>

using namespace std;

int a[1000001];
int c[1000001];
int dx[2];
int f;

void bfs(int x) {
    queue<int> q;
    q.push(x);
    c[x] = 1;

    while(!q.empty()) {
        x = q.front();
        q.pop();

        for(int i=0; i<2; i++) {
            int nx = x + dx[i];
            if(0 < nx && nx <= f) {
                if(c[nx] == 0) {
                    q.push(nx);
                    c[nx] = c[x] + 1;
                }
            }
        }
    }
}

int main() {
    int s, g, u, d;

    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    d = -d;
    dx[0] = u;
    dx[1] = d;
    bfs(s);
    int ans = c[g];

    if(ans == 0)
        printf("use the stairs\n");
    else
        printf("%d\n", ans-1);

}
