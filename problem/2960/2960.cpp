#include <cstdio>

int N, K, a[1001];

int main() {
    scanf("%d %d", &N, &K);

    int cnt = 0, ans;
    for(int i=2; i<=N; i++)
        for(int j=i; j<=N; j+=i)
            if(a[j] == 0) {
                a[j] = 1;
                cnt++;
                if(cnt == K) ans = j;
            }
    
    printf("%d\n", ans);

    return 0;
}
