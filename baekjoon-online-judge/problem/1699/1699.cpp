#include <cstdio>

int main() {
    int n;
    int a[100001] = {0,};

    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        a[i] = i;
        for(int j=1; j*j<=i; j++)
            if(a[i] > a[i-j*j] + 1)
                a[i] = a[i-j*j] + 1;
    }

    printf("%d\n", a[n]);

    return 0;
}
