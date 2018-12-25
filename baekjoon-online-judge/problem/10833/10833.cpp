#include <cstdio>

int N, student, apple;

int main() {
    scanf("%d", &N);

    int ans = 0;
    while(N--) {
        scanf("%d %d", &student, &apple);
        ans += (apple % student);
    }

    printf("%d\n", ans);

    return 0;
}
