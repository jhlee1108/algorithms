#include <iostream>

using namespace std;

string s;

int main() {
    cin >> s;

    int ans = 0;
    int ps = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') {
            if(s[i+1] == ')') {
                ans += ps;
                i++;
            }
            else {
                ps++;
            }
        }
        else {
            ans++;
            ps--;
        }
    }

    cout << ans << '\n';

    return 0;
}
