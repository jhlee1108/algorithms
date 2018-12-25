#include <cstdio>

int N, M, arr[2001], dp[2001][2001];

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &arr[i]);
        dp[i][i] = 1;
    }

    for(int i=1; i<N; i++)
        for(int j=1; j+i<=N; j++)
            if(arr[j] == arr[i+j]) {
                if(j+1 == i+j) dp[j][i+j] = 1;
                else dp[j][i+j] = dp[j+1][i+j-1];
            }

    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        int S, E; scanf("%d %d", &S, &E);
        printf("%d\n", dp[S][E]);
    }

    return 0;
}
