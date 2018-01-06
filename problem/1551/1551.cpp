#include <cstdio>

int N, K, A[20];

int main() {
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d,", &A[i]);

    while(K--) {
        for(int i=0; i<N-1; i++)
            A[i] = A[i+1] - A[i];
        N--;
    }

    printf("%d", A[0]);
    for(int i=1; i<N; i++)
        printf(",%d", A[i]);
    printf("\n");

    return 0;
}
