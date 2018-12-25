#include <cstdio>

long long gcd(long long a, long long b) {
    return b ? gcd(b, a%b) : a;
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    long long a, b; scanf("%lld %lld", &a, &b);

    printf("%lld\n", lcm(a, b));

    return 0;
}
