#include <cstdio>

int C, K;

int main() {
    scanf("%d %d", &C, &K);
    int x = 1;
    for(int i=0; i<K; i++)
        x *= 10;

    int ans = (C / x) * x;
    if(C % x >= x / 2) ans += x;

    printf("%d\n", ans);

    return 0;
}
