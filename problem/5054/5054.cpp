#include <cstdio>

int t, n;

int main() {
    scanf("%d", &t);

    while(t--) {
        int min = 1e9, max = 0, x;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            if(min > x) min = x;
            if(max < x) max = x;
        }
        printf("%d\n", (max-min)*2);
    }

    return 0;
}
