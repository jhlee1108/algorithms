#include <cstdio>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

int N, K;
queue<int> q;

int main() {
    scanf("%d %d", &N, &K);

    int ans = INF;
    for(int i=0; i<N; i++) {
        int x; scanf("%d", &x);
        if(x == 1) q.push(i);
        if(q.size() == K) {
            int j = q.front();
            q.pop();
            ans = min(ans, i-j+1);
        }
    }

    printf("%d\n", ans == INF ? -1 : ans);

    return 0;
}
