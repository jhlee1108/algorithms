#include <iostream>
#include <set>

using namespace std;

int n;
string name, status;
set<string> s;

int main() {
    cin >> n;
    while(n--) {
        cin >> name >> status;
        if(status == "enter") s.insert(name);
        else s.erase(name);
    }

    for(auto it=s.rbegin(); it!=s.rend(); it++)
        cout << *it << '\n';

    return 0;
}
