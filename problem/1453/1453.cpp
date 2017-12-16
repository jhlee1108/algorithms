#include <cstdio>

int N, seat[101];

int main() {
    scanf("%d", &N);
    int ans = 0;

    while(N--) {
        int x; scanf("%d", &x);
        if(seat[x]) ans++;
        seat[x] = 1;
    }

    printf("%d\n", ans);

    return 0;
}
