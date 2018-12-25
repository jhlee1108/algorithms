#include <iostream>

using namespace std;

int main() {
    int ans = 0;
    string s; cin >> s;

    for(int i=0; i<s.size(); i++) {
        if(s[i] == 'c')
            if(i+1 < s.size())
                if(s[i+1] == '=' || s[i+1] == '-')
                    i++;
        
        if(s[i] == 'd') {
            if(i+1 < s.size()) {
                if(s[i+1] == '-')
                    i++;
                if(s[i+1] == 'z')
                    if(i+2 < s.size())
                        if(s[i+2] == '=')
                            i+=2;
            }
        }

        if(s[i] == 'l')
            if(i+1 < s.size())
                if(s[i+1] == 'j')
                    i++;

        if(s[i] == 'n')
            if(i+1 < s.size())
                if(s[i+1] == 'j')
                    i++;

        if(s[i] == 's')
            if(i+1 < s.size())
                if(s[i+1] == '=')
                    i++;

        if(s[i] == 'z')
            if(i+1 < s.size())
                if(s[i+1] == '=')
                    i++;

        ans++;
    }

    cout << ans << '\n';

    return 0;
}
