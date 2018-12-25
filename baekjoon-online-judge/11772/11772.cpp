#include <cstdio>
#include <cmath>

int N, P;

int main() {
    scanf("%d", &N);

    int ans = 0;
    while(N--) {
        scanf("%d", &P);
        int num = P / 10;
        int pot = P % 10;
        ans += pow(num, pot);
    }

    printf("%d\n", ans);

    return 0;
}
