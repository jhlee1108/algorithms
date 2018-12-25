#include <cstdio>

int main() {
    int n;
    int s[100001];

    scanf("%d", &n);

    s[0] = 0;
    s[1] = 3;
    s[2] = 7;

    for(int i=3; i<=n; i++) 
        s[i] = (s[i-1]*3 - (s[i-1] - s[i-2])) % 9901;

    printf("%d\n", s[n]);
}
