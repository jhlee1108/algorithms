#include <cstdio>

int main() {
    int ans[10001] = {0,};
    int n;

    scanf("%d", &n);

    while(n--) {
        int x;
        scanf("%d", &x);
        ans[x]++;
    }

    for(int i=0; i<=10000; i++) {
        if(ans[i] == 0) continue;
        for(int j=0; j<ans[i]; j++)
            printf("%d\n", i);
    }

    return 0;
}
