#include <cstdio>
#include <algorithm>

using namespace std;

int N, milk[1000][1000], dp[3][1000][1000];

int find_max(int i, int j, int t) {
    if(i >= N || j >= N) return 0;
    if(dp[t][i][j] != 0) return dp[t][i][j];

    if(milk[i][j] == t)
        return dp[t][i][j] = 1 + max(find_max(i+1, j, (t+1)%3), find_max(i, j+1, (t+1)%3));
    return dp[t][i][j] = max(find_max(i+1, j, t), find_max(i, j+1, t));
}

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &milk[i][j]);

    printf("%d\n", find_max(0, 0, 0));

    return 0;
}
