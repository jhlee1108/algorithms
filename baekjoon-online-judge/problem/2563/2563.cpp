#include <cstdio>

int map[100][100];

int main() {
    int n; scanf("%d", &n);
    while(n--) {
        int x, y; scanf("%d %d", &x, &y);
        for(int i=y; i<y+10; i++)
            for(int j=x; j<x+10; j++)
                map[i][j] = 1;
    }

    int ans = 0;
    for(int i=0; i<100; i++)
        for(int j=0; j<100; j++)
            if(map[i][j] == 1) ans++;

    printf("%d\n", ans);

    return 0;
}
