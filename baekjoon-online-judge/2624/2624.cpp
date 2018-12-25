#include <cstdio>
#include <cstring>
#include <vector>

#define PII pair<int,int>

using namespace std;

int T, k, dp[101][10001];
vector<PII> v;

int go(int n, int x) {
    if(x == 0) return 1;
    if(n == k) return 0;
    if(dp[n][x] != -1) return dp[n][x];

    int ret = 0;
    for(int i=0; i<=v[n].second; i++)
        if(x - v[n].first*i >= 0)
            ret += go(n+1, x-v[n].first*i);

    return dp[n][x] = ret;
}

int main() {
    scanf("%d %d", &T, &k);
    for(int i=0; i<k; i++) {
        int p, n; scanf("%d %d", &p, &n);
        v.push_back(make_pair(p, n));
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", go(0, T));

    return 0;
}
