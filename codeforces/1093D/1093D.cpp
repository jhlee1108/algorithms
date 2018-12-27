#include <cstdio>
#include <vector>

using namespace std;

#define MOD 998244353
#define ll long long

int t, n, m, u, v;
vector<vector<int>> g(300001);
int vertices[2][300001];

void dfs(int vertexNumber, int number, int oddOrEven, ll &sum) {
    vertices[oddOrEven][vertexNumber] = number;
    if (number == 1)
        sum = (sum * 2) % MOD;
    for (auto &x : g[vertexNumber]) {
        if (vertices[oddOrEven][x] == -1)
            dfs(x, (number + 1) % 2, oddOrEven, sum);
        else if (vertices[oddOrEven][x] == number)
            sum = 0;
    }
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            vertices[0][i] = vertices[1][i] = -1;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ll ans = 1;
        ll sumOdd, sumEven;
        for (int i = 1; i <= n; i++) {
            if (vertices[0][i] == -1) {
                sumEven = 1;
                dfs(i, 0, 0, sumEven);
            }
            if (vertices[1][i] == -1) {
                sumOdd = 1;
                dfs(i, 1, 1, sumOdd);
            }
            else continue;
            ans = (ans * (sumEven + sumOdd)) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
