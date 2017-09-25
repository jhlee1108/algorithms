#include <cstdio>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, dp[1000];

int main() {
    scanf("%d", &N);
    fill(dp,dp+N,INF);

    dp[0] = 0;
    for(int i=0; i<N; i++) {
        int A; scanf("%d", &A);
        for(int j=1; j<=A; j++)
            if(i+j < N) dp[i+j] = min(dp[i+j], dp[i]+1);
    }

    int ans = (dp[N-1] == INF ? -1 : dp[N-1]);
    printf("%d\n", ans);

    return 0;
}
