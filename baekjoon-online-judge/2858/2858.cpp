#include <cstdio>

int L, W, R, B;

int main() {
    scanf("%d %d", &R, &B);
    for(int i=1; i<=2000000; i++)
        if((2+R/2)*i-i*i == R+B) {
            W = i;
            break;
        }
    L = R / 2 - W + 2;

    printf("%d %d\n", L, W);

    return 0;
}
