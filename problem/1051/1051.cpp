#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, map[50][50];

int main() {
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%1d", &map[i][j]);

    int ans = 1;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            int length = 1;
            while(i+length < N && j+length < M) {
                int ny = i + length;
                int nx = j + length;
                
                if(0 <= ny && ny < N && 0 <= nx && nx <= M)
                    if(map[i][j] == map[ny][j] && map[ny][j] == map[i][nx] 
                        && map[i][nx] == map[ny][nx]) 
                        ans = max(ans, (length+1) * (length+1));
                length++;
            }
        }

    printf("%d\n", ans);

    return 0;
}
