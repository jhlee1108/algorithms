#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        int n, m, l; scanf("%d %d %d", &n, &m, &l);
        int ans = 0;
        vector<vector<int>> g(10001);
        int check[10001] = {0,};
        check[0] = 1;

        for(int i=0; i<m; i++) {
            int x, y; scanf("%d %d", &x, &y);
            g[x].push_back(y);
        }

        for(int i=0; i<l; i++) {
            int z; scanf("%d", &z);
            if(check[z] == 0) {
                priority_queue<int> q;
                q.push(z);
                check[z] = 1;
                ans++;

                while(!q.empty()) {
                    int x = q.top();
                    q.pop();

                    for(auto &y : g[x]) {
                        if(check[y] == 0) {
                            check[y] = 1;
                            q.push(y);
                            ans++;
                        }
                    }
                }
            }

        }

        printf("%d\n", ans);
    }

    return 0;
}
