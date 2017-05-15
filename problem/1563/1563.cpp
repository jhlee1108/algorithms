#include <cstdio>
#include <cstring>

#define MOD 1000000

int n;
int a[1001][2][3];

int go(int i, int j, int k) {
    if(i == n) return 1;
    int &x = a[i][j][k];
    if(x != -1) return x;

    x = go(i+1, j, 0);
    if(j == 0) x += go(i+1, 1, 0);
    if(k < 2) x += go(i+1, j, k+1);

    return x % MOD;
}

int main() {
    scanf("%d", &n);
    memset(a,-1,sizeof(a));
    printf("%d\n", go(0,0,0));

    return 0;
}
