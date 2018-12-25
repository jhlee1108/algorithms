#include <cstdio>

int main() {
    int n;
    int sum[1001];

    scanf("%d", &n);

    sum[1] = 1;
    sum[2] = 3;

    for(int i=3; i<=n; i++) {
        sum[i] = (sum[i-1] + 2*sum[i-2]) % 10007;
    }

    printf("%d", sum[n]);

    return 0;
}
