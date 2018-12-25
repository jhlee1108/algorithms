#include <cstdio>

int T, cnt[4];
int coin[4] = {25, 10, 5, 1};

int main() {
    scanf("%d", &T);

    while(T--) {
        int c; scanf("%d", &c);
        for(int i=0; i<4; i++) {
            cnt[i] = c / coin[i];
            c = c % coin[i];
        }
        printf("%d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3]);
    }

    return 0;
}
