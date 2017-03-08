#include <cstdio>
#include <cstring>

int main() {
    char word[101];
    int is_palindrome = 1;

    scanf("%s", word);
    int length = strlen(word);
    int mid = (length + 1) / 2;

    for(int i = 0; i < mid; i++) {
        if (word[i] != word[length - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }

    printf("%d", is_palindrome);

    return 0;
}
