#include <iostream>
#include <algorithm>

using namespace std;

string s1, s2;
int dp[1001][1001];

int main() {
    cin >> s1 >> s2;

    for(int i=1; i<=s1.size(); i++) {
        for(int j=1; j<=s2.size(); j++) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    string ans = "";
    int i = s1.size(), j = s2.size();
    while(i != 0 && j != 0) {
        if(s1[i-1] == s2[j-1]) {
            ans = s1[i-1] + ans;
            i--; j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
    }
    
    cout << dp[s1.size()][s2.size()] << '\n';
    cout << ans << '\n';

    return 0;
}
