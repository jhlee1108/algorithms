#include <cstdio>

int main() {
    int n; scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        int x1 = i/1000000;
        int x2 = (i%1000000)/100000;
        int x3 = (i%100000)/10000;
        int x4 = (i%10000)/1000;
        int x5 = (i%1000)/100;
        int x6 = (i%100)/10;
        int x7 = i%10;
        if(i + x1 + x2 + x3 + x4 + x5 + x6 + x7 == n) {
            printf("%d\n", i);
            break;
        }
        if(i == n) printf("0\n");
    }

    return 0;
}
