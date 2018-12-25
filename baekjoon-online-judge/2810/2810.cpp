#include <cstdio>

int main() {
    int n; scanf("%d", &n);
    int ans = 1;
    bool is_L = false;

    for(int i=0; i<n; i++) {
        char c; scanf("\n%c", &c);
        if(c == 'L') {
            is_L = true;
            scanf("%c", &c);
            i++;
        }
        ans++;
    }

    if(is_L) printf("%d\n", ans);
    else printf("%d\n", ans-1);

    return 0;
}
