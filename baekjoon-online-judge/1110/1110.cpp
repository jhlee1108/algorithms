#include <cstdio>

int main() {
    int n;

    scanf("%d", &n);

    int ans = 0;
    int x = n;
    do {
        ans++;
        int a = x/10;
        int b = x%10;
        int c = a + b;
        x = (b*10) + (c%10);
    } while(x != n);

    printf("%d\n", ans);

    return 0;
}
