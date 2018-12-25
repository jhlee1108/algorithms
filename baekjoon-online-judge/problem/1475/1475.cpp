#include <cstdio>

#define MAX(A, B) (A > B ? A : B)

int main() {
    int a[10] = {0,};
    int x;
    int ans = 0;

    while(scanf("%1d", &x) == 1)
        a[x]++;

    x = a[6] + a[9];
    if(x % 2 == 1) a[6] = x / 2 + 1;
    else a[6] = x / 2;
    
    for(int i=0; i<9; i++)
        ans = MAX(ans, a[i]);

    printf("%d\n", ans);

    return 0;
}
