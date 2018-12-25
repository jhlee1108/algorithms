#include <cstdio>

int n, sum, x[100000];
long long ans;

int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x[i]);
        sum += x[i];
    }

    for(int i=0; i<n; i++) {
        sum -= x[i];
        ans += x[i] * sum;
    }

    printf("%lld\n", ans);

    return 0;
}
