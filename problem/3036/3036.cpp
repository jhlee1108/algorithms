#include <cstdio>

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int n; scanf("%d", &n);
    int a[100] = {0,};

    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    for(int i=1; i<n; i++) {
        int x = gcd(a[0], a[i]);
        printf("%d/%d\n", a[0]/x, a[i]/x);
    }

    return 0;
}
