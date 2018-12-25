#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, dp[1000001][2], check[1000001];
vector<vector<int>> graph(1000001);

int find_min(int curr, int parent) {
    int &ret = dp[curr][parent];
    if(ret != -1) return ret;

    check[curr] = 1;
    int sum1 = 1;
    for(auto &x : graph[curr])
        if(!check[x]) sum1 += find_min(x, 1);

    int sum2 = 1e9;
    if(parent) {
        sum2 = 0;
        for(auto &x : graph[curr])
            if(!check[x]) sum2 += find_min(x, 0);
    }

    check[curr] = 0;
    return ret = min(sum1, sum2);
}

int main() {
    scanf("%d", &N);
    int u, v;
    for(int i=1; i<N; i++) {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", min(find_min(1, 0), find_min(1, 1)));

    return 0;
}
