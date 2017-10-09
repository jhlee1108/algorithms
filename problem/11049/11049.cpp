#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

#define PII pair<int,int>
#define ll long long
using namespace std;

int N;
ll dp[500][500];
vector<PII> v;
ll MAX = pow(500,4);

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int r, c; scanf("%d %d", &r, &c);
        v.push_back(make_pair(r, c));
    }

    for(int j=1; j<N; j++)
        for(int i=0; i<N-j; i++) {
            dp[i][j+i] = MAX; 
            for(int k=i; k<j+i; k++)
                dp[i][j+i] = min(dp[i][k] + dp[k+1][j+i] + v[i].first * v[k].second * v[j+i].second,
                                dp[i][j+i]);
    }

    printf("%lld\n", dp[0][N-1]);

    return 0;
}
