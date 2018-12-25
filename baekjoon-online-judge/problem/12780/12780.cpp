#include <iostream>

using namespace std;

string H, N;

int main() {
    cin >> H >> N;

    int ans = 0;
    for(int i=0; i<H.size(); i++)
        if(H[i] == N[0]) {
            if(N.size() == 1) ans++;
            for(int j=1; j<N.size(); j++) {
                if(!(i+j < H.size() && H[i+j] == N[j])) break;
                if(j == N.size()-1) ans++;
            }
        }

    cout << ans << '\n';

    return 0;
}
