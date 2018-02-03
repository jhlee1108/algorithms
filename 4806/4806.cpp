#include <cstdio>

char c;

int main() {
    int ans = 0;
    while(scanf("%c", &c) == 1) if(c == '\n') ans++;
    printf("%d\n", ans);

    return 0;
}
