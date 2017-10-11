#include <iostream>
#include <cstring>

using namespace std;

string seq, s[2];
int dp[2][21][101];

int go(int i, int j, int k) {
    int ret = 0;
    if(s[i][k] != seq[j]) return 0;
    if(j == seq.size()-1) return 1;
    if(dp[i][j][k] != -1) return dp[i][j][k];

    for(int t=k+1; t<s[0].size(); t++)
        ret += go(i^1, j+1, t);

    return dp[i][j][k] = ret;
}

int main() {
    cin >> seq >> s[0] >> s[1];
    memset(dp, -1, sizeof(dp));
    int ans = 0;

    for(int i=0; i<s[0].size(); i++) {
        ans += go(0, 0, i);
        ans += go(1, 0, i);
    }

    cout << ans << '\n';

    return 0;
}
