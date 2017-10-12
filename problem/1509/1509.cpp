#include <iostream>
#include <algorithm>

using namespace std;

string s;
int p[2500][2500];
int dp[2501];

int main() {
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        p[i][i] = 1;
        if(s[i] == s[i+1]) p[i][i+1] = 1;
    }

    for(int i=2; i<s.size(); i++)
        for(int j=0; j+i<s.size(); j++)
            if(s[j] == s[j+i] && p[j+1][j+i-1]) p[j][j+i] = 1;

    for(int i=1; i<=s.size(); i++) {
        dp[i] = dp[i-1] + 1;
        for(int j=i; j>0; j--)
            if(p[j-1][i-1]) dp[i] = min(dp[i], dp[j-1] + 1);
    }

    cout << dp[s.size()] << '\n';

    return 0;
}
