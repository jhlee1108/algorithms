#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

#define PII pair<int,int>

using namespace std;

int N, k, map[2][100000], check[2][100000];
queue<PII> q;

bool clear() {
    int dy[] = {0, 0, 1};
    int dx[] = {-1, 1, k};
    int remove = 0;
    q.push(make_pair(0, 0));
    check[0][0] = 1;

    while(!q.empty()) {
        int qsize = q.size();
        while(qsize--) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for(int i=0; i<3; i++) {
                int ny = (y + dy[i]) % 2;
                int nx = x + dx[i];
                
                if(nx >= N) return true;
                if(nx > remove && !check[ny][nx] && map[ny][nx]) {
                    q.push(make_pair(ny, nx));
                    check[ny][nx] = 1;
                }
            }
        }

        remove++;
    }

    return false;
}

int main() {
    scanf("%d %d", &N, &k);
    for(int i=0; i<N; i++)
        scanf("%1d", &map[0][i]);
    for(int i=0; i<N; i++)
        scanf("%1d", &map[1][i]);

    puts(clear() ? "1" : "0");

    return 0;
}
