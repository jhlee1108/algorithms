#include <cstdio>

int main() {
    int t; scanf("%d", &t);

    while(t--) {
        int h, w, n;
        scanf("%d %d %d", &h, &w, &n);

        int x = (n-1) / h + 1;
        int y = ((n-1) % h) + 1;
        
        if(x/10 == 0)
            printf("%d0%d\n", y, x);
        else
            printf("%d%d\n", y, x);
    }

    return 0;
}
