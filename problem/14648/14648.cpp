#include <cstdio>

int main() {
    int s[1001];
    int n, q; scanf("%d %d", &n, &q);
    
    for(int i=1; i<=n; i++)
        scanf("%d", &s[i]);

    while(q--) {
        int x; scanf("%d", &x);

        if(x == 1) {
            int a, b; scanf("%d %d", &a, &b);
            int ans = 0;

            for(int i=a; i<=b; i++)
                ans += s[i];

            int temp = s[a];
            s[a] = s[b];
            s[b] = temp;

            printf("%d\n", ans);
        }

        else {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            int sum1 = 0, sum2 = 0;

            for(int i=a; i<=b; i++)
                sum1 += s[i];

            for(int i=c; i<=d; i++)
                sum2 += s[i];

            printf("%d\n", sum1-sum2);
        }
    }

    return 0;
}
