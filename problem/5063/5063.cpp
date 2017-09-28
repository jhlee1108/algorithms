#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;

    while(N--) {
        int r, e, c; cin >> r >> e >> c;
        string ans;

        if(r > e-c) ans = "do not advertise";
        else if(r == e-c) ans = "does not matter";
        else ans = "advertise";

        cout << ans << '\n';
    }

    return 0;
}
