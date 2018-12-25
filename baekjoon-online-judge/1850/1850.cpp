#include <cstdio>

long long gcd(long long a, long long b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    long long a, b; scanf("%lld %lld", &a, &b);
    long long count = gcd(a, b);

    for(long long i=0; i<count; i++)
        printf("1");
    printf("\n");

    return 0;
}
