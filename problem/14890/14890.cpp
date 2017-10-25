#include <cstdio>
#include <cmath>

using namespace std;

int N, L, map[100][100];
int ans, x, l, is_left, is_right;

bool check(int y, int cnt) {
    if(abs(x-y) > 1) return false;
    if(x == y) l++;
    else if(x < y) {
        if(!is_left && l < L) return false;
        if(is_left && l < 2*L) return false;
        is_left = 0;
        l = 1;
        x = y;
    }
    else {
        if(is_left && l < L) return false;
        is_left = 1;
        l = 1;
        x = y;
    }
    if(cnt == N-1) {
        if(is_left && l < L) return false;
        ans++;
    }
    return true;
}

int main() {
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &map[i][j]);

    for(int i=0; i<N; i++) {
        x = map[i][0];
        l = 1, is_left = 0, is_right = 0;
        for(int j=1; j<N; j++)
            if(!check(map[i][j], j)) break;
    }

    for(int j=0; j<N; j++) {
        x = map[0][j];
        l = 1, is_left = 0, is_right = 0;
        for(int i=1; i<N; i++)
            if(!check(map[i][j], i)) break;
    }
    
    printf("%d\n", ans);

    return 0;
}
