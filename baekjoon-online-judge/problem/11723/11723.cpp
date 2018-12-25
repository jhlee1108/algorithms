#include <iostream>
#include <cstdio>

using namespace std;

int M, x, s;
string cmd;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> M;

    while(M--) {
        cin >> cmd;
        
        if(cmd == "add") {
            cin >> x;
            s |= (1 << x);
        }
        else if(cmd == "remove") {
            cin >> x;
            s &= ~(1 << x);
        }
        else if(cmd == "check") {
            cin >> x;
            printf("%d\n", (s & (1 << x)) == (1 << x));
        }
        else if(cmd == "toggle") {
            cin >> x;
            s ^= (1 << x);
        }
        else if(cmd == "all") s = (1 << 21) - 1;
        else s = 0;
    }

    return 0;
}
