#include <iostream>
#include <vector>
#include <algorithm>

#define PIS pair<int,string>

using namespace std;

int T, N, cnt;
string name;
vector<PIS> v;

int main() {
    cin >> T;

    while(T--) {
        cin >> N;
        v.clear();
        
        while(N--) {
            cin >> name >> cnt;
            v.push_back(make_pair(cnt, name));
        }

        sort(v.begin(), v.end(), greater<PIS>());

        cout << v[0].second << '\n';
    }

    return 0;
}
