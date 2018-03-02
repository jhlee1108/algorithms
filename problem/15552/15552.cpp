#include <cstdio>

int T, A, B;

int main() {
    scanf("%d", &T);
    
    while(T--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", A+B);
    }

    return 0;
}
