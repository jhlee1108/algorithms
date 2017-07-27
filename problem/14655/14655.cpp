#include <cstdio>

int main() {
    int n; scanf("%d", &n);
    int ans = 0;

    while(n--) {
        int x; scanf("%d", &x);
        
        if(x < 0) x = -x;
        ans += x;
    }

    printf("%d\n", 2*ans);

    return 0;
}
