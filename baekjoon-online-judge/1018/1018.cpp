#include <cstdio>
#include <algorithm>

using namespace std;

int N, M, map[50][50];

int main() {
    scanf("%d %d\n", &N, &M);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++) {
            char c; scanf("%c\n", &c);
            map[i][j] = (c == 'W' ? 0 : 1);
        }

    int ans = 64;
    for(int i=0; i<N-7; i++)
        for(int j=0; j<M-7; j++) {
            int c1 = 0, c2 = 1, ans1 = 0, ans2 = 0;
            for(int r=i; r<i+8; r++) {
                for(int c=j; c<j+8; c++) {
                    if(map[r][c] != c1) ans1++;
                    if(map[r][c] != c2) ans2++;
                    c1 ^= 1; c2 ^= 1;
                }
                c1 ^= 1; c2 ^= 1;
            }
            ans = min(ans, min(ans1, ans2));
        }

    printf("%d\n", ans);

    return 0;
}
