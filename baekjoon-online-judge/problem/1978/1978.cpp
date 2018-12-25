#include <cstdio>

bool is_prime(int a) {
    bool ans = true;

    if(a == 1) return false;

    for(int i=2; i<a; i++) {
        if(a % i == 0) {
            ans = false;
            break;
        }
    }

    return ans;
}

int main() {
    int n;
    int ans = 0;

    scanf("%d", &n);

    while(n--) {
        int a;
        scanf("%d", &a);
        if(is_prime(a)) ans++;
    }

    printf("%d\n", ans);

    return 0;
}
