#include <cstdio>

int N, cur_milk, next_milk;

int main() {
    scanf("%d", &N);

    int ans = 0;
    for(int i=0; i<N; i++) {
        scanf("%d", &next_milk);
        if(cur_milk == next_milk) {
            cur_milk = (cur_milk + 1) % 3;
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
