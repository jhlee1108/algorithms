#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int N, S[21][21], check[21], score[2];
int ans = INT_MAX;

void go(int k, int cnt) {
    if(cnt == N/2) {
        score[0] = score[1] = 0;
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                if(check[i] == check[j])
                    score[check[i]] += S[i][j];
        ans = min(ans, abs(score[0] - score[1]));
        return;
    }

    for(int i=k+1; i<=N; i++) {
        check[i] = 1;
        go(i, cnt+1);
        check[i] = 0;
    }
}

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            scanf("%d", &S[i][j]);

    for(int i=1; i<=N/2+1; i++) {
        check[i] = 1;
        go(i, 1);
        check[i] = 0;
    }

    printf("%d\n", ans);

    return 0;
}
