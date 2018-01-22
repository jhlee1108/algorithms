#include <cstdio>
#include <cmath>

double d, w, h;

int main() {
    scanf("%lf %lf %lf", &d, &h, &w);
    
    double height = sqrt(pow(d, 2) / (1 + pow(w/h, 2)));
    double width = w / h * height;
    printf("%d %d\n", int(height), int(width));

    return 0;
}
