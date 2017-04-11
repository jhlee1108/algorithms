#include <cstdio>

int main() {
    int n;
    int ans=99;

    scanf("%d", &n);

    for(int i=100; i<=n; i++) {
        int a = i/100;
        int b = (i/10)%10;
        int c = i%10;

        if(c-b == b-a)
            ans++;
    }

    if(n < 100)
        printf("%d\n", n);
    else
        printf("%d\n", ans);

    return 0;
}
