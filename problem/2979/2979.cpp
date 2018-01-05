#include <cstdio>

int fee[4], cnt[101], start, end;

int main() {
    scanf("%d %d %d", &fee[1], &fee[2], &fee[3]);
    fee[2] *= 2;
    fee[3] *= 3;

    for(int i=0; i<3; i++) {
        scanf("%d %d", &start, &end);
        for(int t=start; t<end; t++)
            cnt[t]++;
    }
    
    int ans = 0;
    for(int i=1; i<=100; i++)
        ans += fee[cnt[i]];

    printf("%d\n", ans);

    return 0;
}
