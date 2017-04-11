#include <cstdio>

int main() {
    int n;
    int ans[1000001];

    ans[1] = 1;
    ans[2] = 2;

    scanf("%d", &n);

    for(int i=3; i<=n; i++)
        ans[i] = (ans[i-2] + ans[i-1]) % 15746;

    printf("%d", ans[n]);

    return 0;
}
