#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    int a[10001] = {0,};
    int ans = 0;
    int x = 10001;

    scanf("%d", &m);
    scanf("%d", &n);

    a[0] = a[1] = 1;
    for(int i=2; i<=n; i++) {
        if(a[i] == 1) continue;
        for(int j=i+i; j<=n; j+=i)
            a[j] = 1;
    }

    for(int i=m; i<=n; i++) {
        if(a[i] == 0) {
            ans += i;
            x = min(x, i);
        }
    }

    if(ans == 0) printf("-1\n");
    else printf("%d\n%d\n", ans, x);

    return 0;
}
