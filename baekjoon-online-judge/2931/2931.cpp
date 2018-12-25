#include <cstdio>

int R, C, sy, sx;
char map[25][25];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool left(int y, int x) {
    return map[y][x] == '+' || map[y][x] == '-' || map[y][x] == '1' || map[y][x] == '2';
}

bool right(int y, int x) {
    return map[y][x] == '+' || map[y][x] == '-' || map[y][x] == '3' || map[y][x] == '4';
}

bool up(int y, int x) {
    return map[y][x] == '+' || map[y][x] == '|' || map[y][x] == '1' || map[y][x] == '4';
}

bool down(int y, int x) {
    return map[y][x] == '+' || map[y][x] == '|' || map[y][x] == '2' || map[y][x] == '3';
}

void print(int y, int x, char block) {
    printf("%d %d %c\n", y+1, x+1, block);
}

bool find_block(int y, int x, int dir) {
    if(dir == 0) {
        if(0 <= x-1 && 0 <= y-1 && x+1 < C && left(y, x-1) && up(y-1, x) && right(y, x+1)) {
            print(y, x, '+');
            return true;
        }
        else if(0 <= x-1 && left(y, x-1)) {
            print(y, x, '4');
            return true;
        }
        else if(0 <= y-1 && up(y-1, x)) {
            print(y, x, '|');
            return true;
        }
        else if(x+1 < C && right(y, x+1)) {
            print(y, x, '1');
            return true;
        }
        else return false;
    }
    
    else if(dir == 1) {
        if(y+1 < R && 0 <= y-1 && x+1 < C && down(y+1, x) && up(y-1, x) && right(y, x+1)) {
            print(y, x, '+');
            return true;
        }
        else if(y+1 < R && down(y+1, x)) {
            print(y, x, '4');
            return true;
        }
        else if(0 <= y-1 && up(y-1, x)) {
            print(y, x, '3');
            return true;
        }
        else if(x+1 < C && right(y, x+1)) {
            print(y, x, '-');
            return true;
        }
        else return false;
    }

    else if(dir == 2) {
        if(0 <= x-1 && y+1 < R && x+1 < C && left(y, x-1) && down(y+1, x) && right(y, x+1)) {
            print(y, x, '+');
            return true;
        }
        else if(0 <= x-1 && left(y, x-1)) {
            print(y, x, '3');
            return true;
        }
        else if(0 <= y-1 && down(y+1, x)) {
            print(y, x, '|');
            return true;
        }
        else if(x+1 < C && right(y, x+1)) {
            print(y, x, '2');
            return true;
        }
        else return false;
    }

    else {
        if(0 <= x-1 && 0 <= y-1 && y+1 < R && left(y, x-1) && up(y-1, x) && down(y+1, x)) {
            print(y, x, '+');
            return true;
        }
        else if(0 <= x-1 && left(y, x-1)) {
            print(y, x, '-');
            return true;
        }
        else if(0 <= y-1 && up(y-1, x)) {
            print(y, x, '2');
            return true;
        }
        else if(y+1 < R && down(y+1, x)) {
            print(y, x, '1');
            return true;
        }
        else return false;
    }
}

void dfs(int y, int x, int dir) {
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    
    if(0 <= ny && ny < R && 0 <= nx && nx < C) {
        if(map[ny][nx] == '.' && find_block(ny, nx, dir)) return;
        if(dir == 0) {
            if(map[ny][nx] == '+' || map[ny][nx] == '|')
                dfs(ny, nx, 0);
            else if(map[ny][nx] == '1')
                dfs(ny, nx, 1);
            else if(map[ny][nx] == '4')
                dfs(ny, nx, 3);
        }
        else if(dir == 1) {
            if(map[ny][nx] == '+' || map[ny][nx] == '-')
                dfs(ny, nx, 1);
            else if(map[ny][nx] == '3')
                dfs(ny, nx, 0);
            else if(map[ny][nx] == '4')
                dfs(ny, nx, 2);
        }
        else if(dir == 2) {
            if(map[ny][nx] == '+' || map[ny][nx] == '|')
                dfs(ny, nx, 2);
            else if(map[ny][nx] == '2')
                dfs(ny, nx, 1);
            else if(map[ny][nx] == '3')
                dfs(ny, nx, 3);
        }
        else {
            if(map[ny][nx] == '+' || map[ny][nx] == '-')
                dfs(ny, nx, 3);
            else if(map[ny][nx] == '1')
                dfs(ny, nx, 2);
            else if(map[ny][nx] == '2')
                dfs(ny, nx, 0);
        }
    }
}

int main() {
    scanf("%d %d\n", &R, &C);
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++) {
            scanf("%c\n", &map[i][j]);
            if(map[i][j] == 'M') {
                sy = i;
                sx = j;
            }
        }

    for(int i=0; i<4; i++)
        dfs(sy, sx, i);

    return 0;
}
