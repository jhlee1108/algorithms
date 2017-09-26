#include <cstdio>

int N;

int main() {
    scanf("%d", &N);

    int ans = 0;
    for(int i=0; i<5; i++) {
        int x; scanf("%d", &x);
        if(x == N) ans++;
    }

    printf("%d\n", ans);

    return 0;
}
