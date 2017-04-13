#include <cstdio>

int main() {
    int n, m, l;
    int seat[41] = {0,};
    int ans[41] = {0,};

    scanf("%d", &n);
    scanf("%d", &m);

    while(m--) {
        scanf("%d", &l);
        seat[l] = 1;
    }

    ans[0] = 1;
    ans[1] = 1;

    for(int i=2; i<=n; i++) {
        if(seat[i-1] == 1 || seat[i] == 1)
            ans[i] = ans[i-1];
        else
            ans[i] = ans[i-2] + ans[i-1];
    }

    printf("%d\n", ans[n]);

    return 0;
}
    
