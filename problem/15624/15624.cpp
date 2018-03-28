#include <cstdio>

#define MOD 1000000007

int fibo[1000001], n;

int main() {
    scanf("%d", &n);
    
    fibo[0] = 0; fibo[1] = 1;
    for(int i=2; i<=n; i++)
        fibo[i] = (fibo[i-2] + fibo[i-1]) % MOD;

    printf("%d\n", fibo[n]);

    return 0;
}
