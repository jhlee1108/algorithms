#include <cstdio>

int N, t;

int main() {
    scanf("%d", &N);

    int Y = 0, M = 0;
    while(N--) {
        scanf("%d", &t);
        if(t != 0) {
            Y += (1 + t / 30) * 10;
            M += (1 + t / 60) * 15;
        }
    }

    if(Y > M) printf("M %d\n", M);
    else if(Y < M) printf("Y %d\n", Y);
    else printf("Y M %d\n", Y);

    return 0;
}
