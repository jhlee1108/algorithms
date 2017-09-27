#include <cstdio>

int H, M;

int main() {
    scanf("%d %d", &H, &M);

    int h = H;
    int m = (M + 15) % 60;
    if(M < 45) h = (H + 23) % 24;

    printf("%d %d\n", h, m);

    return 0;
}
