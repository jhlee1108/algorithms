#include <cstdio>
#include <algorithm>

using namespace std;

char map[10][10], new_map[10][10];
int R, C;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int main() {
    scanf("%d %d\n", &R, &C);
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            scanf("%c\n", &map[i][j]);

    int min_i = 1e9, max_i = 0, min_j = 1e9, max_j = 0;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) {
            new_map[i][j] = map[i][j];
            if(new_map[i][j] == 'X') {
                int cnt = 0;
                for(int k=0; k<4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(0 <= ny && ny < R && 0 <= nx && nx < C) {
                        if(map[ny][nx] == '.') cnt++;
                    }
                    else cnt++;
                }
                if(cnt >= 3) new_map[i][j] = '.';
                else {
                    min_i = min(min_i, i);
                    max_i = max(max_i, i);
                    min_j = min(min_j, j);
                    max_j = max(max_j, j);
                }
            }
        }

    for(int i=min_i; i<=max_i; i++) {
        for(int j=min_j; j<=max_j; j++)
            printf("%c", new_map[i][j]);
        printf("\n");
    }

    return 0;
}
