#include <cstdio>

int T, n;
int check[10001];

int main() {
    scanf("%d", &T);

    for(int i=2; i<=100; i++) {
        if(check[i]) continue;

        for(int j=i+i; j<=10000; j+=i)
            check[j] = 1;
    }

    while(T--) {
        scanf("%d", &n);

        for(int i=n/2; i>=2; i--) {
            if(check[i]) continue;
            if(check[n-i]) continue;
            printf("%d %d\n", i, n-i);
            break;
        }
    }

    return 0;
}
