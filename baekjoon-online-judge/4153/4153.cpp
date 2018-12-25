#include <cstdio>

int a, b, c;

int main() {
    while(1) {
        scanf("%d %d %d", &a, &b, &c);

        if(a == 0 && b == 0 && c == 0) break;

        if(a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a)
            puts("right");
        else
            puts("wrong");
    }

    return 0;
}
