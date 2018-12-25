#include <cstdio>

int main() {
    int n;

    scanf("%d", &n);

    int x = 0;
    int y;
    for(int i=1; i<=n; i++) {
        x += i;
        if(n-x <= 0) {
            y = i;
            break;
        }
    }

    int z = n - (x-y);
    if(y%2 == 1)
        printf("%d/%d\n", (y+1)-z, z);
    else
        printf("%d/%d\n", z, (y+1)-z);

    return 0;
}
