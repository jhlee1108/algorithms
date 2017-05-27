#include <iostream>

using namespace std;

int main() {
    string s;
    int ans = 0;

    cin >> s;

    for(int i=0; i<s.size(); i++) {
        int x = s[i] - 'A';
        if(x <= 2) ans += 3;
        else if(x <= 5) ans += 4;
        else if(x <= 8) ans += 5;
        else if(x <= 11) ans += 6;
        else if(x <= 14) ans += 7;
        else if(x <= 18) ans += 8;
        else if(x <= 21) ans += 9;
        else ans += 10;
    }

    cout << ans << '\n';

    return 0;
}
