#include <cstdio>

int e, f, c;

int main() {
    scanf("%d %d %d", &e, &f, &c);
    int ans = 0;
    int n = e + f;

    while(n / c > 0) {
        ans += (n / c);
        n = (n % c) + (n / c);
    }

    printf("%d\n", ans);

    return 0;
}
