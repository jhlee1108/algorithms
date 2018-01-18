#include <cstdio>

int T, N, K, cnt;

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d %d", &N, &K);
        
        int ans = 0;
        while(N--) {
            scanf("%d", &cnt);
            ans += cnt / K;
        }

        printf("%d\n", ans);
    }

    return 0;
}
