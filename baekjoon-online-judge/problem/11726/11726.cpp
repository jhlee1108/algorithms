#include <cstdio>

int main() {
    int n;
    int count[1001];

    scanf("%d", &n);
    
    count[1] = 1;
    count[2] = 2;

    for(int i=3; i<=n; i++) {
        count[i] = (count[i-1] + count[i-2]) % 10007;
    }

    printf("%d", count[n]);

    return 0;
}

