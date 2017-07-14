#include <cstdio>

int main() {
    int ans = 1;
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    while(!((a+1)/2 == (b+1)/2)) {
        a = (a+1)/2;
        b = (b+1)/2;
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
