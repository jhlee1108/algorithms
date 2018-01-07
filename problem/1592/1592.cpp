#include <cstdio>

int N, M, L, cnt[1000];

int main() {
    scanf("%d %d %d", &N, &M, &L);
    int curr = 0, ans = 0;
    
    while(true) {
        cnt[curr]++;
        if(cnt[curr] == M) break;
        if(cnt[curr] % 2 == 0) curr = (N + curr - L) % N;
        else curr = (curr + L) % N;
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
