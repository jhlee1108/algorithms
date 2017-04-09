#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int m, n, i, j;
    vector<int> a;

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        a.push_back(i);

    while(m--) {
        cin >> i >> j;
        reverse(a.begin()+(i-1), a.begin()+j);
    }

    for(auto x : a)
        cout << x << ' ';

    return 0;
}
