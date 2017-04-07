#include <iostream>
#include <map>

using namespace std;

int main() {
    string a, b, c;
    map<string, long> m = {{"black", 0}, {"brown", 1}, {"red", 2},
                            {"orange", 3}, {"yellow", 4}, {"green", 5},
                            {"blue", 6}, {"violet", 7}, {"grey", 8},
                            {"white", 9}};
    
    cin >> a >> b >> c;

    long ans = m[a]*10 + m[b];
    for(int i=1; i<=m[c]; i++)
        ans *= 10;

    cout << ans;

    return 0;
}
