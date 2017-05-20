#include <cstdio>
#include <queue>

using namespace std;

void go() {
    int n, m;
    int ans = 1;
    queue<int> q;
    priority_queue<int> p;

    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        q.push(x);
        p.push(x);
    }

    while(!q.empty()) {
        if(q.front() == p.top()) {
            if(m == 0) {
                printf("%d\n", ans);
                break;
            }
            q.pop();
            p.pop();
            ans++;
        }

        else {
            q.push(q.front());
            q.pop();

            if(m == 0)
                m = q.size();
        }
        
        m--;
    }
}

int main() {
    int t;

    scanf("%d", &t);

    while(t--) {
        go();
    }

    return 0;
}
