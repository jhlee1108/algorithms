#include <cstdio>

int main() {
    int n, k;
    int a[10];

    scanf("%d %d", &n, &k);

    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    int ans = 0;
    int i = n-1;
    while(k > 0) {
        if(k - a[i] >= 0) {
            k -= a[i];
            ans++;
        }
        else 
            i--;
    }

    printf("%d\n", ans);

    return 0;
}
