#include <iostream>
#include <cmath>

using namespace std;

string word1, word2;
int cnt1[26], cnt2[26];

int main() {
    cin >> word1 >> word2;
    
    for(int i=0; i<word1.size(); i++)
        cnt1[word1[i]-'a']++;
    for(int i=0; i<word2.size(); i++)
        cnt2[word2[i]-'a']++;

    int ans = 0;
    for(int i=0; i<26; i++)
        ans += abs(cnt1[i] - cnt2[i]);

    cout << ans << '\n';

    return 0;
}
