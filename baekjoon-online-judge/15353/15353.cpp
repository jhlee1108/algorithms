#include <iostream>

using namespace std;

string A, B, ans;

int main() {
    cin >> A >> B;
    int asize = A.size()-1;
    int bsize = B.size()-1;
    int x = 0, t = 0;
    
    while(asize >= 0 || bsize >= 0 || x > 0) {
        if(asize >= 0) t += (A[asize] - '0');
        if(bsize >= 0) t += (B[bsize] - '0');
        t += x;
        ans = char((t % 10) + '0') + ans;
        x = t / 10;
        t = 0;
        asize--;
        bsize--;
    }

    cout << ans << '\n';

    return 0;
}
