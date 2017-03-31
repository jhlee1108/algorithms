#include <cstdio>

int main() {
    int n;
    long pinary[100];

    scanf("%d" ,&n);
    
    if(n < 3) {
        printf("1");
        return 0;
    }

    pinary[0] = 1;
    pinary[1] = 1;

    for(int i=2; i<n; i++) {
        pinary[i] = pinary[i-1] + pinary[i-2];
    }

    printf("%ld", pinary[n-1]);

    return 0;
}

