#include <cstdio>
#include <vector>
#include <algorithm>

#define PII pair<int,int>

using namespace std;

vector<PII> v;
int dp[1002][17][17];

int main() {
    int w, b;
    v.push_back(make_pair(0, 0));
    while(scanf("%d %d", &w, &b) == 2) {
        v.push_back(make_pair(w, b));
    }

    for(int k=1; k<=v.size()-1; k++)
        for(int i=0; i<=15; i++)
            for(int j=0; j<=15; j++) {
                dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j]);
                dp[k][i+1][j] = max(dp[k][i+1][j], dp[k-1][i][j] + v[k].first);
                dp[k][i][j+1] = max(dp[k][i][j+1], dp[k-1][i][j] + v[k].second);
            }

    printf("%d\n", dp[v.size()-1][15][15]);

    return 0;
}
