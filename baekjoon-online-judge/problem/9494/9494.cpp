#include <iostream>

using namespace std;

int N;
string s;

int main() {
    while(1) {
        cin >> N;
        if(N == 0) break;
        int ans = 0;
        getline(cin, s);
        while(N--) {
            getline(cin, s);
            int len = s.length();
            for(; ans<len; ans++)
                if(s[ans] == ' ') break;
        }
        
        cout << ans+1 << '\n';
    }

    return 0;
}
