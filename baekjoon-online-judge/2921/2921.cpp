#include <cstdio>

int N;

int main() {
    scanf("%d", &N);

    int ans = 0;
    for(int i=1; i<=N; i++)
        ans += i*(i+1) + i*(i+1)/2;

    printf("%d\n", ans);

    return 0;
}
