#include <cstdio>

#define ll long long
#define MOD 1000000007

int N;
ll C, K;

ll pow(ll x, ll y) {
    if(y <= 0) return 1;
    if(y == 1) return x;

    ll ret = pow(x, y/2);
    ret = (ret * ret) % MOD;

    if(y%2 == 1) return (ret * x) % MOD;
    else return ret;
}

int main() {
    scanf("%d", &N);

    ll ans = 0;
    for(int i=0; i<N; i++) {
        scanf("%lld %lld", &C, &K);
        ll ck = (C * K) % MOD;
        if(K > 1) ck = (ck * pow(2, K-1)) % MOD;
        ans = (ans + ck) % MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
