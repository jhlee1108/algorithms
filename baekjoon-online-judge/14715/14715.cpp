#include <cstdio>
#include <algorithm>

#define INF 10000000

using namespace std;

int K, dp[1000001];

int find_min(int x) {
    int ret = INF;

    if(dp[x] >= 0) return dp[x];

    for(int i=2; i*i<=x; i++)
        if(x%i == 0) ret = min(ret, max(find_min(i), find_min(x/i)));

    return dp[x] = ret + 1;
}

int main() {
    scanf("%d", &K);
 
    for(int i=2; i<=K; i++) {
        if(dp[i] < 0) continue;
        for(int j=i+i; j<=K; j+=i)
            dp[j] = -1;
    }

    printf("%d\n", find_min(K));
    
    return 0;
}
