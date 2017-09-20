#include <cstdio>

int main() {
    int T; scanf("%d", &T);

    while(T--) {
        int sum = 0;

        for(int i=16; i>0; i--) {
            int n; scanf("%1d", &n);
            if(i%2 == 0) {
                n *= 2;
                if(n/10 != 0) n = n/10 + (n%10);
            }
            sum += n;
        }
        
        puts(sum%10 ? "F" : "T");
    }

    return 0;
}
