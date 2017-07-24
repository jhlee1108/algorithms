#include <cstdio>

int main() {
    int ans = 0;
    int s_h, s_m, e_h, e_m, n;
    scanf("%d %d %d %d %d", &s_h, &s_m, &e_h, &e_m, &n);

    while(s_h != e_h || s_m != e_m) {
        int x = s_h / 10;
        int y = s_h % 10;
        int a = s_m / 10;
        int b = s_m % 10;

        if(x == n) ans++;
        else if(y == n) ans++;
        else if(a == n) ans++;
        else if(b == n) ans++;

        s_m++;

        if(s_m >= 60) {
            s_m = 0;
            s_h++;
        }
    }

    int x = s_h / 10;
    int y = s_h % 10;
    int a = s_m / 10;
    int b = s_m % 10;

    if(x == n) ans++;
    else if(y == n) ans++;
    else if(a == n) ans++;
    else if(b == n) ans++;

    printf("%d\n", ans);

    return 0;
}
