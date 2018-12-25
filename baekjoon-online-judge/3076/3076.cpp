#include <cstdio>

int R, C, A, B, n;
char color[] = {'X', '.'};

int main() {
    scanf("%d %d %d %d", &R, &C, &A, &B);

    for(int r=0; r<R; r++)
        for(int a=0; a<A; a++) {
            n = r % 2 == 0 ? 0 : 1;
            for(int c=0; c<C; c++) {
                for(int b=0; b<B; b++)
                    printf("%c", color[n]);
                n = (n + 1) % 2;
            }
            printf("\n");
        }
    
    return 0;
}
