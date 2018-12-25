#include <cstdio>
#include <queue>

#define PII pair<int,int>

using namespace std;

int n;
priority_queue<PII, vector<PII>, greater<PII>> pq;

int main() {
    int ans = 0;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++) {
        int s, e; scanf("%d %d", &s, &e);
        pq.push(make_pair(s, e));
    }

    int s = pq.top().first;
    int e = pq.top().second;
    pq.pop();

    while(!pq.empty()) {
        int ns = pq.top().first;
        int ne = pq.top().second;
        pq.pop();

        if(e < ns) {
            ans += (e - s);
            s = ns;
            e = ne;
        }

        else {
            if(ne > e) e = ne;
        }
    }

    ans += (e - s);
    printf("%d\n", ans);

    return 0;
}    
