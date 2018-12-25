#include <cstdio>

int gcd(int a, int b) {
    int r;
    while(true) {
        r = a % b;
        if(r == 0) return b;
        a = b; b = r;
    }
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", lcm(a, b));
    }

    return 0;
}
