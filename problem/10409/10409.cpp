#include <cstdio>

int n, T, task;

int main() {
    scanf("%d %d", &n, &T);

    int total_time = 0;
    int ans = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &task);
        if(total_time + task <= T) {
            total_time += task;
            ans++;
        }
        else break;
    }

    printf("%d\n", ans);

    return 0;
}
