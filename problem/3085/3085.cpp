#include <cstdio>
#include <algorithm>

using namespace std;

int n, ans;
char a[51][51];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void find_max(int i, int j) {
    int s = 1;
    for(int k=1; k<n; k++) {
        if(a[i][k] == a[i][k+1]) s++;
        else {
            ans = max(ans, s);
            s = 1;
        }
    }
    ans = max(ans, s);
    s = 1;
    for(int k=1; k<n; k++) {
        if(a[k][j] == a[k+1][j]) s++;
        else {
            ans = max(ans, s);
            s = 1;
        }
    }
    ans = max(ans, s);
}

int main() {
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("\n%c\n", &a[i][j]);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            find_max(i, j);
            for(int k=0; k<4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(1 <= ni && ni <= n && 1 <= nj && nj <= n) {
                    swap(a[i][j], a[ni][nj]);
                    find_max(i, j);
                    swap(a[i][j], a[ni][nj]);
                }
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
