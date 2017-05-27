#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    int ans = 0;
    int a[26];

    cin >> n;

    while(n--) {
        string s; cin >> s;
        memset(a, 0, sizeof(a));
        int state = 0;
        char c;

        for(int i=0; i<s.size(); i++) {
            if(a[s[i]-'a'] == 0) {
                c = s[i];
                a[c-'a'] = 1;
            }
            else if(c != s[i] && a[s[i]-'a'] != 0) {
                state = 1;
                break;
            }
        }

        if(state == 0) ans++;
    }

    cout << ans << '\n';

    return 0;
}
