#include <cstdio>
#include <algorithm>

using namespace std;

int N, T, K[101], S[101], dp[101][10001];
int main() {
    scanf("%d %d", &N, &T);
    for(int i=1; i<=N; i++)
        scanf("%d %d", &K[i], &S[i]);

    for(int i=1; i<=N; i++)
        for(int j=1; j<=T; j++) {
            if(j >= K[i])
                dp[i][j] = max(S[i] + dp[i-1][j-K[i]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }

    printf("%d\n", dp[N][T]);

    return 0;
}
