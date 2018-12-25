#include <iostream>
#include <list>

using namespace std;

int main() {
    int n;
    list<pair<int,int>> l;

    cin >> n;

    for(int i=1; i<=n; i++) {
        int x;
        cin >> x;
        l.push_back({x,i});
    }

    auto it = l.begin();

    for(int i=0; i<n-1; i++) {
        int s = it->first;
        cout << it->second << ' ';

        if(s > 0) {
            auto temp = it;
            ++temp;
            if(temp == l.end())
                temp = l.begin();
            l.erase(it);
            it = temp;
            for(int i=1; i<s; i++) {
                ++it;
                if(it == l.end())
                    it = l.begin();
            }
        }

        else {
            s = -s;
            auto temp = it;
            if(temp == l.begin())
                temp = l.end();
            --temp;
            l.erase(it);
            it = temp;
            for(int i=1; i<s; i++) {
                if(it == l.begin())
                    it = l.end();
                --it;
            }
        }
    }

    cout << l.front().second << '\n';

    return 0;
}

