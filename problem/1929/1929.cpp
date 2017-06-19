#include <cstdio>

int main() {
    int m, n;
    int a[1000001] = {0,};
    a[0] = 1;
    a[1] = 1;

    scanf("%d %d", &m, &n);

    for(int i=2; i<=n; i++) {
        for(int j=i+i; j<=n; j+=i) {
            if(a[j] == 0) a[j] = 1;
        }
    }

    for(int i=m; i<=n; i++)
        if(a[i] == 0) printf("%d\n", i);

    return 0;
}
