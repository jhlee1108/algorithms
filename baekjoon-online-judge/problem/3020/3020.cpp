#include <cstdio>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    int n, h;
    int u[500005] = {0,};
    int d[500005] = {0,};
    int count[500005] = {0,};

    scanf("%d %d", &n, &h);

    for(int i=1; i<=(n/2); i++) {
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        u[x]++;
        d[y]++;
    }

    int temp = n/2;
    int temp2 = n/2;
    for(int i=1; i<=h; i++) {
        temp -= u[i-1];
        temp2 -= d[i-1];
        count[i] += temp;
        count[h-i+1] += temp2;
    }

    sort(count, count+h+1);

    int ans = count[1];
    int c = 1;
    for(int i=2; i<=h; i++) {
        if(ans == count[i]) c++;
        else break;
    }

    printf("%d %d\n", ans, c);

    return 0;
}
