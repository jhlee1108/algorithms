#include <cstdio>

#define MAX(A, B) A > B ? A : B

int n, m, in, out;

int main() {
    scanf("%d %d", &n, &m);
    int ans = m;

    while(n--) {
        scanf("%d %d", &in, &out);
        m = m + in - out;
        if(m < 0) {
            ans = 0;
            break;
        }
        ans = MAX(ans, m);
    }

    printf("%d\n", ans);

    return 0;
}
