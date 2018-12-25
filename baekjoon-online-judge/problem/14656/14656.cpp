#include <cstdio>

#define MAX(A, B) (A > B ? A : B)

int main() {
    int n; scanf("%d", &n);
    int ans = 0;

    for(int i=1; i<=n; i++) {
        int x; scanf("%d", &x);
        
        if(i != x) ans++;
    }

    printf("%d\n", ans);

    return 0;
}
