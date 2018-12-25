#include <cstdio>

int main() {
    int n; scanf("%d", &n);

    if(n % 2 == 0) printf("I LOVE CBNU\n");
    else {
        for(int i=0; i<n; i++)
            printf("*");
        printf("\n");

        for(int i=0; i<=n/2; i++) {
            for(int j=n/2; j>i; j--)
                printf(" ");
            printf("*");

            if(i != 0) {
                for(int j=0; j<2*(i-1)+1; j++)
                    printf(" ");
                printf("*");
            }

            printf("\n");
        }
    }

    return 0;
}
