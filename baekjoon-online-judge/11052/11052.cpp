#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int p[1001];
    int max_value[1001][1001];

    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        scanf("%d", &p[i]);

        for(int j=1; j<=n; j++) {
            if(j == 1)
                max_value[i][j] = i * p[j];
            else if(j > i)
                max_value[i][j] = max_value[i][j-1];
            else
                max_value[i][j] = max(max_value[i][j-1], max_value[i-j][j] + p[j]);
        }
    }

    printf("%d", max_value[n][n]);

    return 0;
}
