#include <cstdio>

int N, M;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    scanf("%d %d", &N, &M);
    printf("%d\n", M-gcd(N, M));

    return 0;
}
