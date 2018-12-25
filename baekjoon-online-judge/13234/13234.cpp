#include <iostream>

using namespace std;

int main() {
    string a, b, op;
    int aa, bb, ans;


    cin >> a >> op >> b;

    if(a == "true") aa = 1; else aa = 0;
    if(b == "true") bb = 1; else bb = 0;
    if(op == "AND") ans = aa & bb;
    else ans = aa | bb;

    if(ans == 1)
        cout << "true" << '\n';
    else cout << "false" << '\n';

    return 0;
}
