#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, dp[1001][1001], ps[1001];

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);
        
        for(int i=1; i<=N; i++) {
            scanf("%d", &dp[i][i]);
            ps[i] = ps[i-1] + dp[i][i];
        }

        for(int i=1; i<N; i++)
            for(int j=1; i+j<=N; j++)
                dp[j][i+j] = ps[i+j] - ps[j-1] - min(dp[j+1][i+j], dp[j][i+j-1]);

        printf("%d\n", dp[1][N]);
    }

    return 0;
}
