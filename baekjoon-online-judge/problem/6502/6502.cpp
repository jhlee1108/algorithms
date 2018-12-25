#include <cstdio>
#include <cmath>

double r, w, l;

int main() {
    int n = 1;
    while(scanf("%lf", &r) && r != 0) {
        scanf("%lf %lf", &w, &l);
        if(2*r >= sqrt(w*w+l*l)) printf("Pizza %d fits on the table.\n", n++);
        else printf("Pizza %d does not fit on the table.\n", n++);
    }

    return 0;
}
