#include <cstdio>
#include <cmath>

int N, W, H;

int main() {
    scanf("%d %d %d", &N, &W, &H);
    
    while(N--) {
        int x; scanf("%d", &x);
        if(x <= W || x <= H || x <= int(sqrt(W*W+H*H)))
            puts("DA");
        else
            puts("NE");
    }

    return 0;
}
