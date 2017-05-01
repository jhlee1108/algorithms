#include <cstdio>
#include <queue>

using namespace std;

int main() {
    int d[100001] = {0,};
    queue<pair<int,int>> q;
    int n, k;
    int cnt = 1;

    scanf("%d %d", &n, &k);
    q.push(make_pair(n,cnt));
    d[n] = cnt++;

    while(!q.empty()) {
        int x = q.front().first;
        cnt = q.front().second + 1;
        q.pop();

        for(int i=-1; i<3; i++) {
            int nx = x+i;
            if(i == 2)
                nx = x*2;

            if(0 <= nx && nx <= 100000) {
                if(d[nx] == 0) {
                    q.push(make_pair(nx,cnt));
                    d[nx] = cnt;
                }
            }
        }
    }

    printf("%d\n", d[k]-1);

    return 0;
}
