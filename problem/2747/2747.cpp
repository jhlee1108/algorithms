#include <cstdio>

int main() {
    int n;
    int a[46];

    scanf("%d", &n);
    a[0] = 0;
    a[1] = 1;

    for(int i=2; i<=n; i++)
        a[i] = a[i-1] + a[i-2];

    printf("%d\n", a[n]);

    return 0;
}
