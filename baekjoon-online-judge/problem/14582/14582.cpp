#include <cstdio>

int a[9];
int b[9];

int main() {
    bool ans = false;
    int ps_a = 0, ps_b = 0;

    for(int i=0; i<9; i++)
        scanf("%d", &a[i]);
    for(int i=0; i<9; i++)
        scanf("%d", &b[i]);

    for(int i=0; i<9; i++) {
        ps_a += a[i];
        if(ps_a > ps_b) ans = true;
        ps_b += b[i];
    }

    puts(ans ? "Yes" : "No");

    return 0;
}
