#include <cstdio>

#define ll long long
#define MOD 1000000

ll F[2][2] = {{1, 1}, {1, 0}};

void mult_i() {
    ll f1 = (F[0][0] + F[0][1]) % MOD;
    ll f2 = F[0][0];
    ll f3 = (F[1][0] + F[1][1]) % MOD;
    ll f4 = F[1][0];
    F[0][0] = f1; F[0][1] = f2;
    F[1][0] = f3; F[1][1] = f4;

}

void mult_f() {
    ll f1 = (F[0][0]*F[0][0] + F[0][1]*F[1][0]) % MOD;
    ll f2 = (F[0][0]*F[0][1] + F[0][1]*F[1][1]) % MOD;
    ll f3 = (F[1][0]*F[0][0] + F[1][1]*F[1][0]) % MOD;
    ll f4 = (F[1][0]*F[0][1] + F[1][1]*F[1][1]) % MOD;
    F[0][0] = f1; F[0][1] = f2;
    F[1][0] = f3; F[1][1] = f4;
}

void fibo(ll n) {
    if(n <= 1) return;
    ll k = n / 2;
    fibo(k);
    mult_f();
    if(n%2 == 1) mult_i();
}

int main() {
    ll n; scanf("%lld", &n);
    fibo(n-1);
    printf("%lld\n", F[0][0] % MOD);
    return 0;
}
