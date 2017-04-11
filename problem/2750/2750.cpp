#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, input;
    vector<int> v;

    cin >> n;
    
    while(n--) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    for(auto x : v)
        cout << x << endl;

    return 0;
}
