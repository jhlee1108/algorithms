#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, map[1000][1000], dp[1000][1000], left[1000], right[1000];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d", &map[i][j]);

    dp[0][0] = map[0][0];
    for(int i=1; i<M; i++)
        dp[0][i] = dp[0][i-1] + map[0][i];

    for(int i=1; i<N; i++) {
        left[0] = dp[i-1][0] + map[i][0];
        right[M-1] = dp[i-1][M-1] + map[i][M-1];
        for(int j=1; j<M; j++) {
            left[j] = max(left[j-1], dp[i-1][j]) + map[i][j];
            right[M-1-j] = max(right[M-j], dp[i-1][M-1-j]) + map[i][M-1-j];
        }
        for(int j=0; j<M; j++)
            dp[i][j] = max(left[j], right[j]);
    }

    printf("%d\n", dp[N-1][M-1]);

    return 0;
}
