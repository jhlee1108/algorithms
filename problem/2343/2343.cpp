#include <cstdio>

int n, m, a[100000];

int main() {
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);

    int i = 0, j = 1000000000;

    while(i + 1 < j) {
        int mid = (i + j) / 2;

        int c = 1;
        int ps = 0;
        for(int k=0; k<n; k++) {
            if(mid < a[k]) {
                c = 1000000;
                break;
            }
            if(ps + a[k] > mid) {
                ps = a[k];
                c++;
            }
            else ps += a[k];
        }

        if(c > m) i = mid;
        else j = mid;
    }

    printf("%d\n", j);

    return 0;
}
