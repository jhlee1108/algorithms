#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, a;
    set<int> s;

    cin >> n;

    while(n--) {
        cin >> a;
        s.insert(a);
    }

    for(auto x : s)
        cout << x << ' ';

    return 0;
}
