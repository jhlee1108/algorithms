#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    string input;
    vector<string> v;

    cin >> n;

    while(n--) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), [](string a, string b) {
        if(a.size() < b.size())
            return true;
        else if(a.size() > b.size())
            return false;
        else {
            if(a.compare(b) < 0)
                return true;
            else
                return false;
        }
    });

    auto u = unique(v.begin(), v.end());
    v.erase(u, v.end());

    for(auto x : v)
        cout << x << endl;

    return 0;
}
