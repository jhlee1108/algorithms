#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a[10000];

int main() {
    scanf("%d", &n);

    int total = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        total += a[i];
    }

    scanf("%d", &m);

    sort(a, a+n);

    if(total <= m)
        printf("%d\n", a[n-1]);

    else {
        int i = 1, j = m + 1;

        while(i + 1 < j) {
            int mid = (i + j) / 2;

            int s = 0;
            for(int k=0; k<n; k++)
                s += (a[k] <= mid ? a[k] : mid);

            if(s <= m) i = mid;
            else j = mid;
        }

        printf("%d\n", i);
    }
    return 0;
}
