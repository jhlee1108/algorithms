#include <iostream>
#include <map>

using namespace std;

int N, R;
map<int,int> m;

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int e, n; cin >> e >> n;
        m[e] = n;
    }

    cin >> R;
    while(R--) {
        int l; cin >> l;
        string ans = "";
        bool check = false;
        do {
            int s; cin >> s;
            map<int,int>::iterator iter = m.find(s);
            l--;
            if(iter == m.end()) {
                check = true;
                continue;
            }

            ans += (to_string(iter->second) + " ");
        } while(l > 0);

        if(check) cout << "YOU DIED\n";
        else cout << ans << '\n';
    }

    return 0;
}
