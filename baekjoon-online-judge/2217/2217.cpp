#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    priority_queue<int> q;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        int t;
        scanf("%d", &t);
        q.push(t);
    }

    int ans = q.top();
    int cnt = 1;
    q.pop();
    while(!q.empty()) {
        int x = q.top();
        q.pop();
        cnt++;
        if(x*cnt >= ans)
            ans = x*cnt;
    }

    printf("%d\n", ans);

    return 0;
}

