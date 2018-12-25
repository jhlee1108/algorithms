#include <cstdio>
#include <cstring>

int n;
int check[100000];

int main() {
    while(1) {
        scanf("%d", &n);
        if(n == -1) break;
        
        memset(check, 0, sizeof(check));
        int m = 1;
        int i;
        for(i=2; i*i<n; i++)
            if(n%i == 0) {
                check[i] = check[n/i] = 1;
                m = m + i + n/i;
            }

        if(i*i == n) {
            check[i] = 1;
            m += i;
        }

        if(n == m) {
            printf("%d = 1", n);
            for(int i=2; i<n; i++)
                if(check[i] == 1)
                    printf(" + %d", i);
            printf("\n");
        }
        else printf("%d is NOT perfect.\n", n);
    }

    return 0;
}
