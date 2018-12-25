#include <cstdio>

int main() {
    int c, n;
    float a[1000];

    scanf("%d", &c);

    while(c--) {
        scanf("%d", &n);

        float sum = 0;
        for(int i=0; i<n; i++) {
            scanf("%f", &a[i]);
            sum += a[i];
        }

        float avg = sum/n;
        float x = 0;
        for(int i=0; i<n; i++)
            if(a[i] > avg) x++;

        printf("%.3f%%\n", (x/n)*100);
    }

    return 0;
}
