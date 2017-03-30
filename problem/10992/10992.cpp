#include <cstdio>

int main() {
    int n;

    scanf("%d", &n);

    for(int i=0; i<n-1; i++) {
        for(int j=i; j<n-1; j++)
            printf(" ");

        for(int j=0; j<2*i+1; j++) {
            if(j == 0 || j == 2*i)
                printf("*");
            else
                printf(" ");
        }

        printf("\n");
    }

    for(int i=0; i<2*n-1; i++)
        printf("*");

    return 0;
}
