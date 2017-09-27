#include <cstdio>

long long S;

int main() {
    scanf("%lld", &S);

    int N = 0, i = 1;
    while(S) {
        if(S-i >= i+1 || S-i == 0) {
            S -= i;
            N++;
        }
        i++;
    }

    printf("%d\n", N);

    return 0;
}
