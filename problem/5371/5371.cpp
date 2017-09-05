#include <cstdio>
#include <queue>

#define PII pair<int,int>

using namespace std;

int T, N, M;
queue<PII> q;

int main() {
    scanf("%d", &T);
    while(T--) {
        while(!q.empty()) q.pop();
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            int x, y; scanf("%d %d", &x, &y);
            q.push(make_pair(x, y));
        }
        scanf("%d", &M);
        for(int i=0; i<M; i++) {
            int x, y; scanf("%d %d", &x, &y);
            int q_size = q.size();
            while(q_size--) {
                int px = q.front().first;
                int py = q.front().second;
                q.pop();

                if(!(x-50 <= px && px <= x+50 && y-50 <= py && py <= y+50))
                    q.push(make_pair(px, py));
            }
        }
        int q_size = q.size();
        printf("%d\n", N-q_size);
    }

    return 0;
}
