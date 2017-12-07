#include <cstdio>

char c;

int main() {
    
    while(scanf("%c", &c) == 1) {
        if('a' <= c && c <= 'z') {
            int x = c - 'a';
            x = (x + 13) % 26;
            c = 'a' + x;
        }
        else if('A' <= c && c <= 'Z') {
            int x = c - 'A';
            x = (x + 13) % 26;
            c = 'A' + x;
        }

        printf("%c", c);
    }

    return 0;
}
