#include <cstdio>

int main() {
    int n;

    scanf("%d", &n);

    int x = 1;
    for(int i=0; i<n; i++) {
        x += 6*i;
        if(n-x <= 0) {
            printf("%d\n", i+1);
            break;
        }
    }

    return 0;
}
