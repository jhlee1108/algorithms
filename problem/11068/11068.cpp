#include <cstdio>
#include <cstring>

int num[100];

int convert2b(int n, int b) {
    int ret = 0;

    while(n > 0) {
        num[ret++] = n%b;
        n /= b;
    }

    return ret;
}

bool is_palindrome(int n_size) {
    for(int i=0, j=n_size-1; i<j; i++, j--)
        if(num[i] != num[j]) return false;
    return true;
}

int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        bool ans = false;
        for(int i=2; i<=64; i++) {
            memset(num, 0, sizeof(num));
            int n_size = convert2b(n, i);
            ans = is_palindrome(n_size);
            if(ans) break;
        }
        puts(ans ? "1" : "0");
    }
    return 0;
}
