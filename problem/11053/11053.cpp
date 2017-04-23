#include <cstdio>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main() {
    int n;
    int a[1000] = {0,};
    int d[1000] = {0,};
    int ans = 0;

    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    for(int i=0; i<n; i++) {
        d[i] = 1;
        for(int j=0; j<i; j++)
            if(a[j] < a[i] && d[i] < d[j] + 1)
                d[i] = d[j] + 1;
        ans = MAX(ans, d[i]);
    }

    printf("%d\n", ans);

    return 0;
}
