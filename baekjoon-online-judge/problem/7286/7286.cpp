#include <cstdio>

int t, n, a, b;
char letter;
int cnt[1001];

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d\n", &n);
        for(int i=0; i<=1000; i++)
            cnt[i] = 0;
        while(n--) {
            scanf("%c %d %d\n", &letter, &a, &b);
            for(int i=a; i<b; i++)
                cnt[i]++;
        }
        for(int i=0; i<=1000; i++)
            if(cnt[i] > 0) printf("%c", 'A'+cnt[i]-1);
        printf("\n");
    }
    
    return 0;
}
