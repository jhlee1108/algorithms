#include <cstdio>

#define MIN(A,B) (A > B ? B : A)

int main() {
    int a[5555] = {0,};
    int n;
    
    scanf("%d", &n);

    a[1] = -1;
    a[2] = -1;
    a[3] = 1;
    a[4] = -1;
    a[5] = 1;

    for(int i=6; i<=n; i++) {
        if(a[i-3] == -1 && a[i-5] == -1)
            a[i] = -1;
        else if(a[i-3] == -1)
            a[i] = a[i-5] + 1;
        else if(a[i-5] == -1)
            a[i] = a[i-3] + 1;
        else
            a[i] = MIN(a[i-3], a[i-5]) + 1;
    }

    printf("%d\n", a[n]);

    return 0;
}
