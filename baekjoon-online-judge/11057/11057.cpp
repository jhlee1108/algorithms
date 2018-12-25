#include <cstdio>

int main() {
    int n;
    int count[1001][10] = {0,};
    int sum = 0;

    for(int i=0; i<10; i++)
        count[1][i] = 1;

    for(int i=2; i<1001; i++) {
        count[i][0] = 1;
        for(int j=1; j<10; j++)
            count[i][j] = (count[i-1][j] + count[i][j-1]) % 10007;
    }

    scanf("%d", &n);

    for(int i=0; i<10; i++)
        sum = (sum + count[n][i]) % 10007;

    printf("%d", sum);

    return 0;
}
