#include <cstdio>

int N;

int main() {
    scanf("%d", &N);

    int i = 0, j = 1, sum = 0, ans = 0;
    while(i < j) {
        if(sum > N) sum -= i++;
        else sum += j++;
        if(sum == N) ans++;
    }

    printf("%d\n", ans);

    return 0;
}
