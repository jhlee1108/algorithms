#include <cstdio>

int t, x;

int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &x);
        if (x % 2 == 0)
            printf("%d\n", x / 2);
        else
            printf("%d\n", (x - 3) / 2 + 1);
    }
    return 0;
}