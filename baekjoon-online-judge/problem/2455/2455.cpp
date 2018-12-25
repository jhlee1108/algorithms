#include <cstdio>

#define MAX(A,B) (A > B ? A : B)

int main() {
    int prev = 0;
    int ans = 0;

    for(int i=0; i<4; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        prev = prev - a + b;
        ans = MAX(ans, prev);
    }

    printf("%d\n", ans);

    return 0;
}
