#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int N, M, a[301][21], dp[301][21], path[301][21];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++) {
        int index; scanf("%d", &index);
        for(int j=1; j<=M; j++)
            scanf("%d", &a[index][j]);
    }

    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++) {
            if(dp[i][j-1] > a[i][j]) path[i][j] = 0;
            else path[i][j] = i;
            dp[i][j] = max(dp[i][j-1], a[i][j]);
            for(int k=i-1; k>0; k--) {
                if(dp[i][j] < dp[k][j-1] + a[i-k][j])
                    path[i][j] = i-k;
                dp[i][j] = max(dp[i][j], dp[k][j-1] + a[i-k][j]);
            }
        }

    printf("%d\n", dp[N][M]);
    
    stack<int> s;    
    for(int i=M; i>0; i--) {
        s.push(path[N][i]);
        N -= path[N][i];
    }
    while(!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");

    return 0;
}
