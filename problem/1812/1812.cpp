#include <cstdio>

int N, psum[1000];

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &psum[i]);

    int ans = 0;
    for(int i=1; i<=N; i++)
        i % 2 == 0 ? ans -= psum[i] : ans += psum[i];
    ans /= 2;
    
    printf("%d\n", ans);
    for(int i=1; i<N; i++) {
        ans = psum[i] - ans;
        printf("%d\n", ans);
    }

    return 0;
}
