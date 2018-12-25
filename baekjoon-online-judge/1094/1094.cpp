#include <cstdio>

int main() {
    int ans = 0;
    int a; scanf("%d", &a);
    int len = 64;
    int sum = 0;

    while(1) {
        if(sum+len > a) {
            len /= 2;
        }

        else if(sum+len == a) {
            ans++;
            break;
        }

        else {
            sum += len;
            len /= 2;
            ans++;
        }
    }

    printf("%d\n", ans);

    return 0;
}
