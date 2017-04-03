#include <cstdio>

int main() {
    int n;
    int a[10] = {0};
    int b[10] = {0};
    int sum = 0;

    scanf("%d", &n);

    for(int i=1; i<10; i++)
        a[i] = 1;

    for(int k=1; k<n; k++) {
        for(int i=0; i<10; i++) {
            if(i == 0)
                b[i] = a[i+1] % 1000000000;
            else if(i == 9)
                b[i] = a[i-1] % 1000000000;
            else
                b[i] = (a[i-1] + a[i+1]) % 1000000000;
        }

        for(int i=0; i<10; i++)
            a[i] = b[i];
    }

    for(int i=0; i<10; i++)
        sum = (sum + a[i]) % 1000000000 ;

    printf("%d", sum);

    return 0;
}
