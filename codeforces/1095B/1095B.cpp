#include <cstdio>

#define MIN(A, B) (A < B ? A : B)

int n, a, max1, max2, min1, min2;

int main() {
    max1 = max2 = 0;
    min1 = min2 = 1e9;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &a);
        if (max2 < a) {
            if (max1 < a) {
                max2 = max1;
                max1 = a;
            }
            else
                max2 = a;
        }
        if (min2 > a) {
            if (min1 > a) {
                min2 = min1;
                min1 = a;
            }
            else
                min2 = a;
        }
    }

    printf("%d\n", MIN(max1 - min1, MIN(max1 - min2, max2 - min1)));

    return 0;
}
