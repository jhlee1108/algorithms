#include <cstdio>

int main() {
    int t;
    int n;
    int count[11];

    scanf("%d", &t);

    count[1] = 1;
    count[2] = 2;
    count[3] = 4;

    for(int i=0; i<t; i++) {
        scanf("%d", &n);
        
        for(int j=4; j<=n; j++) {
            count[j] = count[j-1] + count[j-2] + count[j-3];
        }

        printf("%d\n", count[n]);
    }

    return 0;
}
