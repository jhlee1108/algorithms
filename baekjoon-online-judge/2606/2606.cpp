#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int n, k, ans;
vector<vector<int>> v(101);
int check[101];

void bfs(int a) {
    queue<int> q;
    q.push(a);
    check[a] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(auto &y : v[x]) {
            if(check[y] == 0) {
                q.push(y);
                check[y] = 1;
                ans++;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);

    for(int i=0; i<k; i++) {
        int x, y; scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    bfs(1);

    printf("%d\n", ans);

    return 0;
}
