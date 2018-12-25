#include <cstdio>

#define MAX(A,B) ((A) > (B) ? (A) : (B))

int main() {
    int a[200] = {0,};
    int d[200] = {0,};
    int n;
    int x = 0;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        d[i] = 1;
        for(int j=0; j<i; j++) {
            if(a[j] < a[i] && d[i] < d[j] + 1)
                d[i] = d[j] + 1;
        }
        x = MAX(x, d[i]);
    }

    printf("%d\n", n-x);

    return 0;
}
