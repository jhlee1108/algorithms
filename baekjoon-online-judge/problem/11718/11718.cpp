#include <cstdio>

int main() {
    char input[101];

    while(scanf("%[^\n]\n", input) == 1) {
        printf("%s\n", input);
    }

    return 0;
}
