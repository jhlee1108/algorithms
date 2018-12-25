#include <iostream>

using namespace std;

int main() {
    string s;
    int d[5001] = {0,};

    cin >> s;
    s = " " + s;
    d[0] = 1;
    for(int i=1; i<s.size(); i++) {
        int a = s[i] - '0';
        
        if(1 <= a && a <= 9)
            d[i] = (d[i] + d[i-1]) % 1000000;

        if(i == 1)
            continue;

        if(s[i-1] == '0')
            continue;

        a = (s[i-1]-'0')*10 + a;
        if(10 <= a && a <= 26)
            d[i] = (d[i] + d[i-2]) % 1000000;
    }

    cout << d[s.size()-1] << '\n';

    return 0;
}
