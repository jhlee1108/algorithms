#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, M, coin[20], dp[10001];

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d", &coin[i]);
        scanf("%d", &M);

        fill(dp, dp+M+1, 0);
        dp[0] = 1;
        for(int i=0; i<N; i++)
            for(int j=coin[i]; j<=M; j++)
                dp[j] += dp[j-coin[i]];
    
        printf("%d\n", dp[M]);
    }

    return 0;
}
