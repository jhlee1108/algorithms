#include <cstdio>

int T, V, E;

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d %d", &V, &E);
        printf("%d\n", -(V-E-2));
    }

    return 0;
}
