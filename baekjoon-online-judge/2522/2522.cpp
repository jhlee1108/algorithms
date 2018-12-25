#include <cstdio>

int main() {
    int n;

    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        for(int j=i; j<n; j++) {
            printf(" ");
        }

        for(int j=0; j<i; j++) {
            printf("*");
        }

        printf("\n");
    }

    for(int i=1; i<=n-1; i++) {
        for(int j=0; j<i; j++) {
            printf(" ");
        }

        for(int j=i; j<n; j++) {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

