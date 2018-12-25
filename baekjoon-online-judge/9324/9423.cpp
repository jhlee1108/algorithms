#include <cstdio>
#include <cstring>

int T, cnt[26];
char c, prev;

int main() {
    scanf("%d\n", &T);

    while(T--) {
        memset(cnt, 0, sizeof(cnt));
        bool is_success = true, is_duplicate = false;
        
        while(scanf("%c", &c) == 1 && !(c == '\n' || c == EOF)) {
            int index = c - 'A';
            cnt[index]++;

            if(is_duplicate) {
                if(prev != c) is_success = false;
                is_duplicate = false;
                cnt[index] = 0;
            }

            if(cnt[index] == 3) {
                is_duplicate = true;
                prev = c;
            }
        }
        
        puts(is_success && !is_duplicate ? "OK" : "FAKE");
    }

    return 0;
}
