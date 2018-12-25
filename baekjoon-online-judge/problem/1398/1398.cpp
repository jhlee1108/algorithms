#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long 
#define INF 1e9

int T;
int dp[100];
int coin[3] = {1, 10, 25};

int main() {
    for(int i=1; i<100; i++) {
        dp[i] = INF;
        for(int j=0; j<3; j++)
            if(i-coin[j] >= 0)
                dp[i] = min(dp[i], dp[i-coin[j]]+1);
    }

    scanf("%d", &T);

    while(T--) {
        ll price; scanf("%lld", &price);
        ll ans = 0;

        while(price) {
            int t = price % 100;
            ans += dp[t];
            price /= 100;
        }

        printf("%lld\n", ans);
    }

    return 0;
}
