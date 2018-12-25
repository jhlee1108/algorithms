#include <cstdio>

int T, k;

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &k);
        int ans = 0;
        while(k--) ans = (ans + 0.5) * 2;
        printf("%d\n", ans);
    }

    return 0;
}
