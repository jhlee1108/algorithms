#include <cstdio>

int n;

int main() {
    scanf("%d", &n);
    int ans = 0;

    for(int i=1; i<=n; i++) {
        if(i*i > n) break;
        ans += n/i - i + 1;
    }

    printf("%d\n", ans);

    return 0;
}
