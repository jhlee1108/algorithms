#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, W[16][16];
int dp[16][1 << 16];
const int INF = 1234567890;

int go(int cur, int visited) {
    int &ret = dp[cur][visited];
    if(dp[cur][visited] != -1) return dp[cur][visited];
    if(visited == (1 << N) - 1) {
        if(W[cur][0] != 0) return W[cur][0];
        else return INF;
    }
    
    ret = INF;
    for(int i=0; i<N; i++) {
        if(visited & (1 << i) || W[cur][i] == 0) continue;
        ret = min(ret, go(i, visited | (1 << i)) + W[cur][i]);
    }

    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &W[i][j]);
    memset(dp, -1, sizeof(dp));

    printf("%d\n", go(0, 1));

    return 0;
}
