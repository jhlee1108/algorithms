#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, i, j, k;
    vector<int> v;

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        v.push_back(i);

    while(m--) {
        cin >> i >> j >> k;
        rotate(v.begin()+(i-1), v.begin()+(k-1), v.begin()+j);
    }

    for(auto x : v)
        cout << x << ' ';

    return 0;
}
