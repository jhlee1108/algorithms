#include <cstdio>
#include <cstring>

int N, cow[11];

int main() {
    scanf("%d", &N);
    memset(cow, -1, sizeof(cow));
    int ans = 0;

    while(N--) {
        int c, l; scanf("%d %d", &c, &l);
        if(cow[c] != -1 && cow[c] != l) ans++;
        cow[c] = l;
    }

    printf("%d\n", ans);

    return 0;
}
