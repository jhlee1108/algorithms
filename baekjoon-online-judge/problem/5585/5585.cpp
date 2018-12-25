#include <cstdio>

int n, cnt;
int coin[] = {500, 100, 50, 10, 5, 1};

int main() {
    int n; scanf("%d", &n);
    n = 1000 - n;

    for(int i=0; i<6; i++)
        if(n / coin[i] != 0) {
            cnt += (n / coin[i]);
            n %= coin[i];
        }

    printf("%d\n", cnt);

    return 0;
}
