#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, P, cost[16][16], dp[1 << 16];
const int MAX = 1e9;

int find_min_cost(int status, int cnt) {
    if(P <= cnt) return 0;

    int &ret = dp[status];
    if(ret != -1) return ret;
    ret = MAX;
    for(int i=0; i<N; i++)
        if((status & (1 << i)))
            for(int j=0; j<N; j++)
                if(!(status & (1 << j)))
                    ret = min(ret, find_min_cost(status | (1 << j), cnt+1) + cost[i][j]);

    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d\n", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d\n", &cost[i][j]);

    int status = 0, cnt = 0; char c;
    for(int i=0; i<N; i++) {
        scanf("%c\n", &c);
        if(c == 'Y') {
            cnt++;
            status |= (1 << i);
        }
    }

    scanf("%d", &P);

    int ans = find_min_cost(status, cnt);
    if(ans == MAX) printf("%d\n", -1);
    else printf("%d\n", ans);

    return 0;
}
