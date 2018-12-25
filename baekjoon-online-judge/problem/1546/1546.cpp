#include <cstdio>

#define MAX(A,B) (A > B ? A : B)

int main() {
    int n;
    float a[1111];
    float m = 0;

    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%f", &a[i]);
        m = MAX(m, a[i]);
    }

    float sum = 0;
    for(int i=0; i<n; i++) {
        a[i] = (a[i]/m)*100;
        sum += a[i];
    }

    if(n != 0)
        printf("%.2f\n", sum/n);
    else
        printf("0.00\n");

    return 0;
}
