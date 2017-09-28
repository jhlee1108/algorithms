#include <cstdio>
#include <algorithm>

using namespace std;

int T, W, plum[1000], dp[31][1000];

int main() {
    scanf("%d %d", &T, &W);
    for(int i=0; i<T; i++)
        scanf("%d", &plum[i]);
    
    for(int i=0; i<=W; i++)
        dp[i][0] = (plum[0] + i) % 2;

    for(int i=1; i<T; i++) {
        for(int j=W; j>=0; j--) {
            if(j == 0) dp[j][i] = dp[j][i-1] + ((plum[i] + j) % 2);
            else dp[j][i] = max(dp[j][i-1] + ((plum[i] + j) % 2),
                            dp[j-1][i-1] + ((plum[i] + j - 1) % 2));
        }
    }

    int ans = 0;
    for(int i=0; i<=W; i++)
        ans = max(ans, dp[i][T-1]);
    printf("%d\n", ans);

    return 0;
}
