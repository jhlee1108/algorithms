#include <cstdio>

int c[100001];

int main() {
    int n, q; scanf("%d", &n);

    for(int i=0; i<n-1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        c[a]++; c[b]++;
    }

    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        int t, k; scanf("%d %d", &t, &k);
        if(t == 1 && c[k] == 1) printf("no\n");
        else printf("yes\n");
    }

    return 0;
}
