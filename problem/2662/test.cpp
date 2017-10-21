#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;
int k, n, x, y, z;
int a[301][21];
int dp[301][21];
pair<int, int> back[301][21];
int func(int val, int pos) {
        if (val == 0)
                    return 0;
                        if (pos > n)
                                    return -INF;
                                        if (val < 0)
                                                    return -INF;
                                                        int &ret = dp[val][pos];
                                                            if (ret != -1)return ret;
                                                                for (int i = 0; i <= k; i++) {
                                                                            if (ret < func(val - i, pos + 1) + a[i][pos]) {
                                                                                            ret = func(val - i, pos + 1) + a[i][pos];
                                                                                                        back[val][pos] = { val - i,pos + 1 };
                                                                                                                }
                                                                                                                    }
                                                                                                                        return ret;
}
int main(){
        memset(dp, -1, sizeof(dp));
            scanf("%d%d", &k, &n);
                while (scanf("%d", &x) != EOF) {
                            for (int i = 1; i <= n; i++)
                                            scanf("%d", &a[x][i]);
                                                }
                                                    printf("%d\n", func(k, 1));
                                                        x = k, y = 1;
                                                            for (int i = 1; i <= n; i++) {
                                                                        printf("%d ", x - back[x][y].first);
                                                                                int cx = x;
                                                                                        x = back[x][y].first;
                                                                                                y = back[cx][y].second;
                                                                                                    }
                                                                                                        return 0;
}


