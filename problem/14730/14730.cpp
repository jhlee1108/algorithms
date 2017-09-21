#include <cstdio>

int N, C, K;

int main() {
    scanf("%d", &N);

    int ans = 0;
    for(int i=0; i<N; i++) {
        scanf("%d %d", &C, &K);
        ans += (C * K);
    }

    printf("%d\n", ans);

    return 0;
}
