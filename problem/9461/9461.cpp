#include <cstdio>

int main() {
    int t;
    int n;
    long p[101];

    p[1] = 1;
    p[2] = 1;
    p[3] = 1;

    for(int i=4; i<101; i++)
        p[i] = p[i-2] + p[i-3];

    scanf("%d" , &t);

    for(int i=0; i<t; i++) {
        scanf("%d", &n);
        printf("%ld\n", p[n]);
    }

    return 0;
}
