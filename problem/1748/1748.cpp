#include <cstdio>
#include <cmath>

int N;

int main() {
    scanf("%d", &N);
    long long ans = 0;

    for(int i=1; i<10; i++) {
        int k = pow(10, i);
        int p = pow(10, i-1);
        if(N/k > 0) ans += ((k-p)*i);
        else {
            ans += (N - p + 1)*i;
            break;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
