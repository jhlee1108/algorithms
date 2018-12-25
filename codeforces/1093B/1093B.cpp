#include <cstdio>

using namespace std;

int t, diff, cnt[26];
char s[1001];

int main() {
    scanf("%d\n", &t);
    for (int i = 0; i < t; i++) {
        scanf("%s", s);
        diff = 0;
        for (int j = 0; j < 26; j++)
            cnt[j] = 0;
        for (int j = 0; s[j] != '\0'; j++) {
            if (cnt[s[j] - 'a'] == 0) diff++;
            cnt[s[j] - 'a']++;
        }
        if (diff == 1)
            printf("-1\n");
        else {
            int k = 0;
            for (int j = 0; j < 26; j++)
                while (cnt[j] != 0) {
                    s[k++] = 'a' + j;
                    cnt[j]--;
                }
            printf("%s\n", s);
        }
    }
}