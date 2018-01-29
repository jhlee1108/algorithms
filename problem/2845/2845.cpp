#include <cstdio>

int L, P, n;

int main() {
    scanf("%d %d", &L, &P);
    
    int cnt = L * P;
    for(int i=0; i<5; i++) {
        scanf("%d", &n);
        printf("%d ", n-cnt);
    }

    return 0;
}
