#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int map[100][100];
int tetris_y[13][4] = {{0, 0, 0, 0},
                    {0, 1, 2, 3},
                    {0, 0, 1, 1},
                    {0, 1, 1, 2},
                    {0, 0, 0, 1},
                    {0, 1, 2, 2},
                    {0, 0, 0, -1},
                    {0, -1, -2, -2},
                    {0, 0, 1, 0},
                    {0, 1, 1, 2},
                    {0, 0, -1, 0},
                    {0, -1, -1, -2},
                    {0, 1, 0, 1}};

int tetris_x[13][4] = {{0, 1, 2, 3},
                    {0, 0, 0, 0},
                    {0, 1, 1, 2},
                    {0, 0, -1, -1},
                    {0, 1, 2, 2},
                    {0, 0, 0, -1},
                    {0, -1, -2, -2},
                    {0, 0, 0, 1},
                    {0, 1, 1, 2},
                    {0, -1, 0, 0},
                    {0, -1, -1, -2},
                    {0, 0, 1, 0},
                    {0, 0, 1, 1}};

int main() {
    int tc = 1;
    while(1) {
        int N; scanf("%d", &N);
        if(!N) return 0;

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                scanf("%d", &map[i][j]);
        
        int ans = INT_MIN;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                for(int k=0; k<13; k++) {
                    int ps = 0;
                    bool is_ok = true;
                    for(int t=0; t<4; t++) {
                        int ny = i + tetris_y[k][t];
                        int nx = j + tetris_x[k][t];
                        if(0 <= ny && ny < N && 0 <= nx && nx < N)
                            ps += map[ny][nx];
                        else is_ok = false;
                    }
                    if(is_ok) ans = max(ans, ps);
                }

        printf("%d. %d\n", tc++, ans);
    }
}
