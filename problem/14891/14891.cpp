#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int K, check[4];
vector<deque<int> > a(4);

void go(int n, int d) {
    check[n] = 1;
    if(n+1 < 4 && a[n][2] != a[n+1][6] && !check[n+1])
        go(n+1, -d);
    if(n-1 >= 0 && a[n][6] != a[n-1][2] && !check[n-1])
        go(n-1, -d);
    if(d == 1) {
        a[n].push_front(a[n].back());
        a[n].pop_back();
    }
    else {
        a[n].push_back(a[n].front());
        a[n].pop_front();
    }
}

int main() {
    for(int i=0; i<4; i++)
        for(int j=0; j<8; j++) {
            int x; scanf("%1d", &x);
            a[i].push_back(x);
        }
    scanf("%d", &K);
    for(int i=0; i<K; i++) {
        int n, d; scanf("%d %d", &n, &d);
        n--;
        memset(check, 0, sizeof(check));
        go(n, d);
    }

    int ans = 0;
    for(int i=0; i<4; i++)
        if(a[i][0]) ans += pow(2, i);
    
    printf("%d\n", ans);

    return 0;
}
