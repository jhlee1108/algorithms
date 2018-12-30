#include <cstdio>

int n;
char c;

int main() {
    scanf("%d\n", &n);
    for (int i = 1; n > 0; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%c", &c);
            n--;
        }
        printf("%c", c);
    }
    return 0;
}
