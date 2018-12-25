#include <cstdio>
#include <algorithm>

#define INF 1e9

using namespace std;

int T, K, ps[501], dp[501][501];

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &K);
        for(int i=1; i<=K; i++) {
            scanf("%d", &ps[i]);
            ps[i] += ps[i-1];
        }
       
        for(int j=1; j<K; j++)
            for(int i=1; i<=K-j; i++) {
                dp[i][i+j] = INF;
                for(int t=i; t<i+j; t++)
                    dp[i][i+j] = min(dp[i][i+j], dp[i][t] + dp[t+1][i+j] 
                                                + ps[i+j] - ps[i-1]);
            }

        printf("%d\n", dp[1][K]);
    }

    return 0;
}
