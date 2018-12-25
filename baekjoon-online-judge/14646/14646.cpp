#include <cstdio>

#define MAX(A, B) (A > B ? A : B)

int a[100001];

int main() {
    int n; scanf("%d", &n);
    int ans = 0;
    int count = 0;

    for(int i=0; i<2*n; i++) {
        int x; scanf("%d", &x);

        if(a[x] == 0) {
            a[x] = 1;
            count++;
            ans = MAX(ans, count);
        }

        else {
            a[x] = 0;
            count--;
        }
    }

    printf("%d\n", ans);

    return 0;
}
