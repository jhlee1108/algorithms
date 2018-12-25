#include <cstdio>

#define MAX(A, B) (A > B ? A : B)

int sum;
int rsum[501];
int csum[501];

int main() {
    int n, m; scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int x; scanf("%d", &x);
            int count = 0;

            do {
                if(x % 10 == 9) count++;
                x /= 10;
            } while(x != 0);

            rsum[i] += count;
            csum[j] += count;
        }

        sum += rsum[i];
    }

    int max = 0;
    for(int i=1; i<=n; i++)
        max = MAX(max, rsum[i]);

    for(int i=1; i<=m; i++)
        max = MAX(max, csum[i]);

    printf("%d\n", sum-max);

    return 0;
}
