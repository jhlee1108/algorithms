#include <iostream>
#include <queue>
#include <cstring>

#define PIS pair<int,string>

using namespace std;

int T, A, B, check[10001];
string d[4] = {"D", "S", "L", "R"};

void bfs() {
    queue<PIS> q;
    string ans = "";
    q.push(make_pair(A, ans));
    check[A] = 1;

    while(!q.empty()) {
        A = q.front().first;
        ans = q.front().second;
        q.pop();
        
        if(A == B) {
            cout << ans << '\n';
            return;
        }

        for(int i=0; i<4; i++) {
            int NA;
            if(i == 0) NA = (A * 2) % 10000;
            else if(i == 1) NA = A == 0 ? 9999 : A-1;
            else if(i == 2) {
                int d1 = A / 1000;
                int d2 = (A % 1000) / 100;
                int d3 = (A % 100) / 10;
                int d4 = A % 10;
                NA = d2*1000 + d3*100 + d4*10 + d1;
            }
            else {
                int d1 = A / 1000;
                int d2 = (A % 1000) / 100;
                int d3 = (A % 100) / 10;
                int d4 = A % 10;
                NA = d4*1000 + d1*100 + d2*10 + d3;
            }

            if(!check[NA]) {
                q.push(make_pair(NA, ans+d[i]));
                check[NA] = 1;
            }
        }
    }
}

int main() {
    cin >> T;

    while(T--) {
        cin >> A >> B;
        memset(check, 0, sizeof(check));
        bfs();
    }

    return 0;
}
