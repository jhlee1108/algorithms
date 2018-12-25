#include <cstdio>
#include <deque>

#define PII pair<int,int>

using namespace std;

int N, K, L, map[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
deque<PII> dq;
int current_direction = 0;

void change_direction(char turn) {
    if(turn == 'L') {
        current_direction = (current_direction + 3) % 4;
    }
    else {
        current_direction = (current_direction + 1) % 4;
    }
}

int main() {
    scanf("%d %d", &N, &K);
    while(K--) {
        int r, c; scanf("%d %d", &r, &c);
        map[r][c] = 1;
    }
    scanf("%d", &L);

    map[1][1] = -1;
    dq.push_back(make_pair(1,1));
    int ans = 0;
    int is_end = false;
    while(L--) {
        int sec; char turn;
        scanf("%d %c\n", &sec, &turn);

        while(ans < sec) {
            ans++;
            int ny = dq.back().first + dy[current_direction];
            int nx = dq.back().second + dx[current_direction];

            if(!(0 < nx && nx <= N && 0 < ny && ny <= N)) {
                is_end = true;
                break;
            }
            if(map[ny][nx] == -1) {
                is_end = true;
                break;
            }
            if(map[ny][nx] == 0) {
                map[dq.front().first][dq.front().second] = 0;
                dq.pop_front();
            }
            map[ny][nx] = -1;
            dq.push_back(make_pair(ny, nx));
        }

        if(is_end) break;

        change_direction(turn);
    }

    while(!is_end) {
        ans++;
        int ny = dq.back().first + dy[current_direction];
        int nx = dq.back().second + dx[current_direction];

        if(!(0 < nx && nx <= N && 0 < ny && ny <= N)) break;
        if(map[ny][nx] == -1) break;
        if(map[ny][nx] == 0) {
            map[dq.front().first][dq.front().second] = 0;
            dq.pop_front();
        }
        map[ny][nx] = -1;
        dq.push_back(make_pair(ny, nx));
    }

    printf("%d\n", ans);

    return 0;
}
