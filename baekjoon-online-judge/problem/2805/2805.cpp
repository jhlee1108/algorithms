#include <cstdio>

int n, m, h[1000000];

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d", &h[i]);

    int i = 0, j = 1000000000;

    while(i+1 < j) {
        int mid = (i + j) / 2;
        long long sum = 0;

        for(int k=0; k<n; k++)
            if(h[k] > mid) sum += (h[k] - mid);

        if(sum >= m) i = mid;
        else j = mid;
    }

    printf("%d\n", i);

    return 0;
}
