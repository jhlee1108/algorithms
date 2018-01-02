#include <cstdio>

#define MAX(A, B) A > B ? A : B

int N, M, B, A[1001], cnt[1001];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", &A[i]);
    
    int ans = 0;
    for(int i=1; i<=M; i++) {
        scanf("%d", &B);
        for(int j=1; j<=N; j++) {
            if(A[j] <= B) {
                cnt[j]++;
                if(cnt[ans] < cnt[j]) ans = j;
                break;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
