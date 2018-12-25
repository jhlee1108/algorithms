#include <cstdio>

int T, N;

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d", &N);
        double s = 0; int p = 0;
        while(N--) {
            int x; double y;
            scanf("%d %lf", &x, &y);
            s += (x * y);
            p += x;
        }
        printf("%d %.1lf\n", p, s / p);
    }

    return 0;
}
