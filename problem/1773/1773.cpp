#include <cstdio>

int N, C;
int time[2000001];

int main() {
    scanf("%d %d", &N, &C);
    for(int i=0; i<N; i++) {
        int p; scanf("%d", &p);
        int x = p;
        while(x <= C) {
            time[x] = 1;
            x += p;
        }
    }

    int ans = 0;
    for(int i=1; i<=C; i++)
        ans += time[i];

    printf("%d\n", ans);

    return 0;
}
