#include <cstdio>

int main() {
    int a[101] = {0,};
    int p, n; scanf("%d %d", &p, &n);

    for(int i=0; i<n; i++) {
        int x; char c; scanf("%d %c", &x, &c);
        if(c == 'R')
            for(int i=x+1; i<=100; i++)
                a[i] = (a[i] + 1) % 3;
        else
            for(int i=x-1; i>=1; i--)
                a[i] = (a[i] + 1) % 3;
    }

    int x = 0, y = 0, z = 0;

    for(int i=1; i<=100; i++) {
        if(a[i] == 0) x++;
        else if(a[i] == 1) y++;
        else z++;
    }

    printf("%.2f\n", p*(x/100.0));
    printf("%.2f\n", p*(y/100.0));
    printf("%.2f\n", p*(z/100.0));

    return 0;
}
