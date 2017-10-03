#include <cstdio>

int n, k;

int main() {
    scanf("%d", &n);

    while(n--) {
        scanf("%d", &k);
        while(k--) printf("=");
        printf("\n");
    }

    return 0;
}
