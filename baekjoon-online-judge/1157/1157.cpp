#include <iostream>

using namespace std;

int main() {
    int a[26] = {0,};
    string s;

    cin >> s;

    for(int i=0; i<s.size(); i++) {
        if('a' <= s[i] && s[i] <= 'z') a[s[i]-'a']++;
        else a[s[i]-'A']++;
    }

    int x = a[0];
    int y = 0;
    for(int i=1; i<26; i++) {
        if(x < a[i]) {
            x = a[i];
            y = i;
        }
    }

    int state = 0;
    for(int i=0; i<26; i++) {
        if(x == a[i] && y != i) {
            state = 1;
            break;
        }
    }

    if(state == 0) cout << char(y+'A') << '\n';
    else cout << '?' << '\n';

    return 0;
}
