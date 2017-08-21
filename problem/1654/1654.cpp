#include <cstdio>

#define ll long long

int k, n;
ll a[10000];

int main() {
    scanf("%d %d", &k, &n);

    for(int i=0; i<k; i++)
        scanf("%lld", &a[i]);

    ll i = 1, j = 2147483648;

    while(i + 1 < j) {
        ll mid = (i + j) / 2;

        int c = 0;
        for(int t=0; t<k; t++) {
            ll x = a[t];
            while(x >= mid) {
                x -= mid;
                c++;
            }
            if(c >= n) break;
        }

        if(c < n) j = mid;
        else i = mid;
    }

    printf("%lld\n", i);

    return 0;
}
