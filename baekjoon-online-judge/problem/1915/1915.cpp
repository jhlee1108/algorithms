#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, arr[1001][1001];

int main() {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%1d", &arr[i][j]);

    int ans = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            if(arr[i][j] && arr[i-1][j-1] && arr[i-1][j] && arr[i][j-1])
                arr[i][j] = min(arr[i-1][j-1], min(arr[i-1][j], arr[i][j-1])) + 1;
            ans = max(ans, arr[i][j]);
        }

    printf("%d\n", ans*ans);

    return 0;
}
