#include <cstdio>

double X, Y;
int N;

int main() {
    scanf("%lf %lf %d", &X, &Y, &N);

    while(N--) {
        double xi, yi; scanf("%lf %lf", &xi, &yi);
        if(X/Y > xi/yi) {
            X = xi;
            Y = yi;
        }
    }

    printf("%.2lf\n", X/Y*1000);

    return 0;
}
