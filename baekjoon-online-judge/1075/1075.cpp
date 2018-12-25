#include <cstdio>

int N, F;

int main() {
    scanf("%d %d", &N, &F);

    int ans = 0;
    N = (N/100)*100 + 99;
    for(int i=0; i<=99; i++) {
        if((N-i) % F == 0)
            ans = (N-i) % 100;
    }

    printf("%02d\n", ans);
    
    return 0;
}
