#include <cstdio>

int main() {
    int sec = 0;
    for(int i=0; i<4; i++) {
        int s; scanf("%d", &s);
        sec += s;
    }

    int x = sec / 60;
    int y = sec % 60;
    printf("%d\n%d\n", x, y);

    return 0;
}
