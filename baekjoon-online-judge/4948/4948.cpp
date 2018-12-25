#include <cstdio>

int main() {
    int n;
    int a[300000] = {0,};
    a[0] = 1;
    a[1] = 1;

    for(int i=2; i<300000; i++)
        for(int j=i+i; j<300000; j+=i)
            if(a[j] == 0) a[j] = 1;

    while(scanf("%d", &n) == 1) {
        if(n == 0)
            break;

        int ans = 0;
        for(int i=2*n; i>n; i--)
            if(a[i] == 0) ans++;

        printf("%d\n", ans);
    }

    return 0;
}
