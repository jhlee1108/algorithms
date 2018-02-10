#include <cstdio>
#include <map>

#define ll long long

using namespace std;

ll N, P, Q;
map<ll, ll> m;

ll find(ll n) {
    if(n == 0) return 1;
    if(m.find(n) != m.end()) return m[n];
    return m[n] = find(n/P) + find(n/Q);
}

int main() {
    scanf("%lld %lld %lld", &N, &P, &Q);
    printf("%lld\n", find(N));

    return 0;
}
