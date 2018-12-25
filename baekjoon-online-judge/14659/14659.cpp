#include <cstdio>

#define MAX(A, B) (A > B ? A : B)

int main() {
    int n; scanf("%d", &n);
    int ans = 0;
    int ps = 0;
    int m = 0;

    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        if(x > m) {
            ans = MAX(ans, ps);
            ps = 0;
            m = x;
        }

        else {
            ps++;
        }
    }

    ans = MAX(ans, ps);

    printf("%d", ans);

    return 0;
}

