#include <cstdio>
#include <algorithm>

using namespace std;
int cs[10001];
int c[101];

int min_cs(int k, int n) {
    if(cs[k] != -1) return cs[k];

    int ret = 100000;
    for(int i=1; i<=n; i++) {
        if(k == c[i]) {
            ret = 1;
            break;
        }
        if(k-c[i] > 0) ret = min(ret, min_cs(k-c[i], n)+1);
    }

    return cs[k] = ret;
}

int main() {
    int n, k; scanf("%d %d", &n, &k);
    fill(cs, cs+10001, -1);

    for(int i=1; i<=n; i++) {
        int x; scanf("%d", &x);
        c[i] = x;
    }

    int ans = min_cs(k, n);
    if(ans == 100000) ans = -1;
    printf("%d\n", ans);

    return 0;
}
