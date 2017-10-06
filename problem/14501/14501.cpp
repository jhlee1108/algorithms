#include <cstdio>
#include <algorithm>

using namespace std;

int N, T[15], P[15], dp[15];

int go(int i) {
    if(i > N-1) return 0;
    if(dp[i] != -1) return dp[i];
    int p = 0;
    if(i+T[i]-1 < N) p = P[i];
    return dp[i] = max(go(i+1), p+go(i+T[i]));
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d %d", &T[i], &P[i]);
        dp[i] = -1;
    }
    
    int ans = 0;
    for(int i=N-1; i>=0; i--)
        ans  = max(ans, go(i));

    printf("%d\n", ans);

    return 0;
}
