#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m;
    string name;
    map<string, int> d;
    int count = 0;

    cin >> n >> m;

    while(n--) {
        cin >> name;
        d[name] = 1;
    }

    while(m--) {
        cin >> name;
        d[name] += 1;
    }

    for(auto x : d) {
        if(x.second == 2)
            count++;
    }

    cout << count << '\n';

    for(auto x : d) {
        if(x.second == 2)
            cout << x.first << '\n';
    }

    return 0;
}

