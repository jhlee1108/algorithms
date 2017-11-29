#include <cstdio>

int N, K, a[10001];

int main() {
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++) {
        if(N % i == 0) a[i] = 1;
    }

    int ans = 0;
    int cnt = 0;
    for(int i=1; i<=N; i++) {
        if(a[i]) cnt++;
        if(cnt == K) {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}
