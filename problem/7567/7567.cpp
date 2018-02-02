#include <iostream>

using namespace std;

string in;

int main() {
    cin >> in;

    int ans = 10;
    char prev = in[0];
    for(int i=1; i<in.size(); i++) {
        if(prev == in[i]) ans += 5;
        else {
            ans += 10;
            prev = in[i];
        }
    }

    cout << ans << '\n';

    return 0;
}
