#include <cstdio>

int T, N, M;

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d %d", &N, &M);
        int ans = 2 * M - N;
        printf("%d %d\n", ans, M-ans);
    }

    return 0;
}
