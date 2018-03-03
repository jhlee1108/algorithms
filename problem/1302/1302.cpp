#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define PIS pair<int,string>

using namespace std;

int N;
map<string,int> m;
vector<PIS> v;

int main() {
    cin >> N;
    while(N--) {
        string book; cin >> book;
        m[book]++;
    }

    for(auto &x : m)
        v.push_back(make_pair(x.second, x.first));

    sort(v.begin(), v.end(), [](const PIS &a, const PIS &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    
    cout << v[0].second << '\n';

    return 0;
}
