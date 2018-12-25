#include <cstdio>

int main() {
    int a, b; scanf("%d %d", &a, &b);
    int ans = 1;

    for(int i=a; i<=b; i++) {
        int x = 0;
        for(int j=1; j<=i; j++)
            x += j;
        ans = ((ans % 14579) * (x % 14579)) % 14579;
    }

    printf("%d\n", ans);

    return 0;
}
