#include <cstdio>

int main() {
    int n;
    int m[31] = {0,};

    scanf("%d", &n);

    m[0] = 1;
    m[2] = 3;

    for(int i=4; i<=n; i+=2) {
        m[i] = 3 * m[i-2];

        for(int j=4; j<=i; j+=2)
            m[i] += (2 * m[i-j]);
    }

    printf("%d", m[n]);

    return 0;
}
