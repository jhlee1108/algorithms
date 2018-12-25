#include <cstdio>

int N;

int main() {
    scanf("%d", &N);

    int psum; scanf("%d", &psum);
    printf("%d ", psum);
    for(int i=2; i<=N; i++) {
        int x; scanf("%d", &x);
        int ans = x*i - psum;
        printf("%d ", ans);
        psum += ans;
    }

    printf("\n");

    return 0;
}
