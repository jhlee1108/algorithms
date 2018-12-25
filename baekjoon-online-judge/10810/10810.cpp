#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, i, j, k;

    cin >> n >> m;
    vector<int> a(n, 0);

    while(m--) {
        cin >> i >> j >> k;
        fill(a.begin()+(i-1), a.begin()+j, k);
    }

    for(auto x : a)
        cout << x << ' ';

    return 0;
}
    
