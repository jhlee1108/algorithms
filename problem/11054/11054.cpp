#include <cstdio>

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

int main() {
    int n;
    int a[1001] = {0,};
    int b[1001] = {0,};
    int c[1001] = {0,};
    int d[1001] = {0,};
    int ans = 0;

    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = b[n-i+1] = x;
    }

    for(int i=1; i<=n; i++) {
        d[i] = c[i] = 1;
        for(int j=1; j<i; j++) {
            if(a[j] < a[i] && d[i] < d[j] + 1)
                d[i] = d[j] + 1;
            if(b[j] < b[i] && c[i] < c[j] + 1)
                c[i] = c[j] + 1;
        }
    }

    for(int i=1; i<=n; i++)
        ans = MAX(ans, d[i] + c[n-i+1] - 1);

    printf("%d\n", ans);

    return 0;
}
