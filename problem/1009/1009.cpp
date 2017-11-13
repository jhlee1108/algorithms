#include <cstdio>

int T, a, b;

int main() {
    scanf("%d", &T);
    
    while(T--) {
        scanf("%d %d", &a, &b);
        int last = 1;
        while(b--) {
            last = (last * a) % 10;
        }
        printf("%d\n", last == 0 ? 10 : last);
    }

    return 0;
}
