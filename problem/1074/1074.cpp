#include <cstdio>
#include <cmath>

int go(int N, int r, int c) {
    if(N == 0) return 0;
    int x = pow(2, N-1);
    if(r < x && c < x) return go(N-1, r, c);
    else if(r < x && c >= x) return x*x + go(N-1, r, c-x);
    else if(r >= x && c < x) return x*x*2 + go(N-1, r-x, c);
    else return x*x*3 + go(N-1, r-x, c-x);
}

int main() {
    int N, r, c;
    scanf("%d %d %d", &N, &r, &c);
    printf("%d\n", go(N, r, c));

    return 0;
}
