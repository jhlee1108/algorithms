#include <cstdio>

int main() {
    int isbn[13];
    int x, k;
    int sum = 0;

    for(int i=0; i<13; i++) {
        char c; scanf("%c\n", &c);
        if(c == '*') x = i;
        isbn[i] = c - 48;
    }

    for(int i=0; i<13; i++) {
        if(i != x) {
            if(i % 2 == 0) k = 1;
            else k = 3;
            sum += (k * isbn[i]);
        }
    }

    if(x % 2 == 0) k = 1;
    else k = 3;

    int ans;
    for(int i=0; i<10; i++) {
        if(((sum + k*i) % 10) == 0) {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}
