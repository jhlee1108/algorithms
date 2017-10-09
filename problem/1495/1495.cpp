#include <cstdio>

int N, S, M, V[100], dp[100][1001];

int main() {
    scanf("%d %d %d", &N, &S, &M);
    for(int i=0; i<N; i++)
        scanf("%d", &V[i]);

    if(S+V[0] <= M) dp[0][S+V[0]] = 1;
    if(0 <= S-V[0]) dp[0][S-V[0]] = 1;
    for(int i=1; i<N; i++)
        for(int j=0; j<=M; j++)
            if(dp[i-1][j]) {
                if(j+V[i] <= M) dp[i][j+V[i]] = 1;
                if(0 <= j-V[i]) dp[i][j-V[i]] = 1;
            }

    int ans = -1;
    for(int i=0; i<=M; i++)
        if(dp[N-1][i]) ans = i;

    printf("%d\n", ans);

    return 0;
}
