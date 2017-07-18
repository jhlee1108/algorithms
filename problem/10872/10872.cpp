#include <cstdio>

int factorial(int a) {
    if(a < 2) return 1;
    else return a * factorial(a-1);
}

int main() {
    int n; scanf("%d", &n);

    printf("%d\n", factorial(n));

    return 0;
}
