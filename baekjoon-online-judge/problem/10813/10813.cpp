#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, i, j;
    int a[101] = {0,};

    cin >> n >> m;

    for(int i=1; i<=n; i++)
        a[i] = i;

    while(m--) {
        cin >> i >> j;
        swap(a[i], a[j]);
    }

    for(int i=1; i<=n; i++)
        cout << a[i] << ' ';

    return 0;
}
