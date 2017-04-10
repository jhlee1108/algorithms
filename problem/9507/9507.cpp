#include <cstdio>

int main() {
    int t, n;
    long long ans[68];

    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;

    for(int i=4; i<=67; i++)
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3] + ans[i-4];

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);
        printf("%lld\n", ans[n]);
    }

    return 0;
}
