#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 1500001

using namespace std;

int N, T[MAX_N], P[MAX_N], dp[MAX_N];

int find_max(int n) {
    int &ret = dp[n];
    if(ret != -1) return ret;
    
    if(n == N) return ret = 0;
    ret = find_max(n+1);
    if(n+T[n] <= N) ret = max(ret, P[n] + find_max(n+T[n]));
    return ret;
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d %d", &T[i], &P[i]);
    memset(dp, -1, sizeof(dp));
   
    printf("%d\n", find_max(0));
    
    return 0;
}
