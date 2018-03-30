#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[100001], n;

int main() {
    scanf("%d", &n);

    memset(dp, -1, sizeof(dp));
    dp[2] = dp[5] = 1;
    dp[4] = 2;
    for(int i=6; i<=n; i++) {
        if(dp[i-2] != -1 && dp[i-5] != -1) dp[i] = min(dp[i-2], dp[i-5]) + 1;
        else if(dp[i-5] != -1) dp[i] = dp[i-5] + 1;
        else if(dp[i-2] != -1) dp[i] = dp[i-2] + 1;
    }
    
    printf("%d\n", dp[n]);

    return 0;
}
