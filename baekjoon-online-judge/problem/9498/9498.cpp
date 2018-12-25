#include <cstdio>

int main() {
    int n;

    scanf("%d", &n);

    int a = n/10;
    if(a >= 9) printf("A\n");
    else if(a == 8) printf("B\n");
    else if(a == 7) printf("C\n");
    else if(a == 6) printf("D\n");
    else printf("F\n");

    return 0;
}
