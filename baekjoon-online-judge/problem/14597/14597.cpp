#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int H, W, B1[100][100], B2[100][100], dp[100][100];
int dx[] = {-1, 0, 1};

int error(int y, int x) {
    int &ret = dp[y][x];
    if(ret != -1) return ret;
    
    ret = pow(B1[y][x]-B2[y][x], 2);
    if(y == H-1) return ret;

    int e = 1e9;
    for(int i=0; i<3; i++) {
        int nx = x + dx[i];
        if(0 <= nx && nx < W)
            e = min(e, error(y+1, nx));
    }

    return ret += e;
}

int main() {
    scanf("%d %d", &H, &W);
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            scanf("%d", &B1[i][j]);
    for(int i=0; i<H; i++)
        for(int j=0; j<W; j++)
            scanf("%d", &B2[i][j]);
    memset(dp, -1, sizeof(dp));
    
    int ans = 1e9;
    for(int i=0; i<W; i++)
        ans = min(ans, error(0, i));

    printf("%d\n", ans);

    return 0;
}
