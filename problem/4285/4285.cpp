#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int k, m, c, r;
vector<string> v;
string s;

int main() {
    while(1) {
        cin >> k;
        if(k == 0) break;
        cin >> m;
        
        v.clear();
        for(int i=0; i<k; i++) {
            cin >> s;
            v.push_back(s);
        }

        bool req = true;
        for(int i=0; i<m; i++) {
            cin >> c >> r;
            int cnt = 0;
            for(int j=0; j<c; j++) {
                cin >> s;
                if(find(v.begin(), v.end(), s) != v.end()) cnt++;
            }
            if(cnt < r) req = false;
        }

        puts(req ? "yes" : "no");
    }

    return 0;
}
