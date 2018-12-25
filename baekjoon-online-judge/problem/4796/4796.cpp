#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int l, p, v;

    for(int i=1;;i++) {
        scanf("%d %d %d", &l, &p, &v);
        if(l == 0 && p == 0 && v == 0) break;

        int ans = 0;
        while(v >= p) {
            ans += l;
            v -= p;
        }
        
        ans += min(l, v);
        printf("Case %d: %d\n", i, ans);
    }

    return 0;
}
