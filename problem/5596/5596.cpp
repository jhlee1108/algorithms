#include <cstdio>

int T, S;

int main() {
    for(int i=0; i<4; i++) {
        int x; scanf("%d", &x);
        S += x;
    }

    for(int i=0; i<4; i++) {
        int x; scanf("%d", &x);
        T += x;
    }

    printf("%d\n", S < T ? T : S);

    return 0;
}
