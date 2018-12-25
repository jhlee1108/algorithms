#include <cstdio>

int N; int map[500][500];

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(int i=y1; i<y2; i++)
            for(int j=x1; j<x2; j++)
                map[i][j] = 1;
    }

    int ans = 0;
    for(int i=0; i<500; i++)
        for(int j=0; j<500; j++)
            ans += map[i][j];

    printf("%d\n", ans);

    return 0;
}
