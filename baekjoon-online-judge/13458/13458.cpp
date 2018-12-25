#include <cstdio>
#include <cmath>

int N, B, C, A[1000001];

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", &A[i]);
    scanf("%d %d", &B, &C);

    long long ans = 0;
    for(int i=1; i<=N; i++) {
        int p = A[i] - B;
        if(p <= 0) {
            ans++;
            continue;
        }

        int t = ceil(((double)p)/C);
        ans += (t + 1);
    }

    printf("%lld\n", ans);

    return 0;
}
