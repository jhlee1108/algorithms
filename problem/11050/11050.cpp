#include <cstdio>

int bc(int n, int k) {
    if(n < 0) return 0;
    if(k > n) return 0;
    if(k == 0) return 1;
    if(n == k) return 1;
    return bc(n-1, k-1) + bc(n-1, k);
}

int main() {
    int n, k; scanf("%d %d", &n, &k);
    int ans = bc(n, k);

    printf("%d\n", ans);

    return 0;
}
