#include <cstdio>

int C;

int main() {
    scanf("%d", &C);
    int ans = 1;
    
    while(C != 1) {
        if(C % 2 == 0) C /= 2;
        else C = C * 3 + 1;
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
