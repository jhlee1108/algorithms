#include <cstdio>

int a[1000];

bool match(int x, int y, int s, int b) {
    int d1[3], d2[3];
    for(int i=0; i<3; i++) {
        d1[i] = x % 10;
        d2[i] = y % 10;
        x /= 10;
        y /= 10;
    }
    
    int s1 = 0, b1 = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(d1[i] == d2[j]) {
                if(i == j) s1++;
                else b1++;
            }
        }
    }

    return s == s1 && b == b1;
}

int main() {
    int n; scanf("%d", &n);

    for(int i=1; i<10; i++) {
        for(int j=1; j<10; j++) {
            if(i == j) continue;
            for(int k=1; k<10; k++) {
                if(j == k || i == k) continue;
                a[100*i+10*j+k] = 1;
            }
        }
    }

    int ans = 504;
    for(int i=0; i<n; i++) {
        int x, s, b; scanf("%d %d %d", &x, &s, &b);
        for(int i=123; i<=987; i++) {
            if(a[i] == 0) continue;
            if(!match(x, i, s, b)) {
                a[i] = 0;
                ans--;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
