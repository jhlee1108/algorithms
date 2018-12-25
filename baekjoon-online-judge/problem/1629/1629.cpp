#include <cstdio>

#define ll long long

ll find(ll a, ll b, ll c) {
    if(b == 1) return a % c;

    ll x = find(a, b/2, c);

    if(b % 2 == 1) return (((x * x) % c) * a) % c;
    return (x * x) % c;
}

int main() {
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    ll ans = find(a, b, c);

    printf("%lld\n", ans);

    return 0;
}
