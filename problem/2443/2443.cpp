#include <cstdio>

int N;

int main() {
    scanf("%d", &N);

    for(int i=0; i<N; i++) {
        for(int j=0; j<i; j++) printf(" ");
        for(int j=1; j<2*N-i*2; j++) printf("*");
        printf("\n");        
    }

    return 0;
}
