#include <iostream>

using namespace std;

int main() {
    string s; cin >> s;
    int ans = 0;
    char per[3] = {'P', 'E', 'R'};

    for(int i=0; i<s.size(); i++)
        if(s[i] != per[i%3]) ans++;

    cout << ans << '\n';

    return 0;
}
