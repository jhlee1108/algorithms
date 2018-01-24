#include <cstdio>

int A, B, C;

int main() {
    scanf("%d %d %d", &A, &B, &C);
    
    if(B >= C) printf("-1\n");
    else printf("%d\n", A/(C-B)+1);

    return 0;
}
