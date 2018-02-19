#include <cstdio>
#include <cstring>

char s1[1001], s2[1001];

int main() {
    scanf("%s\n%s\n", s1, s2);
    puts(strlen(s1) >= strlen(s2) ? "go" : "no");

    return 0;
}
