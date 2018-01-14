#include <cstdio>

int X, Y;

int rev(int a) {
    int ret = 0;
    int i = 1000, j = 1, cnt = 0;
    for(int k=1; k<=1000; k*=10)
        if(a/k > 0) {
            i = k;
            cnt++;
        }
    while(cnt--) {
        ret += (a / i) * j;
        a %= i;
        j *= 10;
        i /= 10;
    }

    return ret;
}

int main() {
    scanf("%d %d", &X, &Y);
    printf("%d\n", rev(rev(X) + rev(Y)));
    
    return 0;
}
