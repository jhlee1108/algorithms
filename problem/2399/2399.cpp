#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    long long a[10000] = {0,};
    long long b[10000] = {0,};

    scanf("%lld", &n);

    for(long long i=0; i<n; i++)
        scanf("%lld", &a[i]);

    sort(a, a+n);

    for(long long i=1; i<n; i++)
        b[0] += (a[i] - a[0]);

    for(long long i=1; i<n; i++) {
        long long x = a[i] - a[i-1];
        b[i] = b[i-1] - (n-i)*x + i*x;
    }

    long long ans = 0;
    for(long long i=0; i<n; i++)
        ans += b[i];

    printf("%lld\n", ans);

    return 0;
}
