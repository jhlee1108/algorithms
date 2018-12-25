#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    int c[1001][1001];
    int s[1001][1001];

    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            scanf("%d", &c[i][j]);
            s[i][j] = c[i][j] + max(s[i][j-1], max(s[i-1][j-1], s[i-1][j]));
        }
    }

    printf("%d", s[n][m]);

    return 0;   
}
